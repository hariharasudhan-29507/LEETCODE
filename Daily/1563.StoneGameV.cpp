class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        if (n == 1) return 0;

        vector<vector<int>> dp(n, vector<int>(n, 0));
        vector<vector<int>> mx(n, vector<int>(n, 0));

        for (int i = 0; i < n; ++i) {
            mx[i][i] = stoneValue[i];
        }

        for (int j = 1; j < n; ++j) {
            int mid = j;
            int sm = stoneValue[j];
            int right = 0;

            for (int i = j - 1; i >= 0; --i) {
                sm += stoneValue[i];

                while (mid > i && (right + stoneValue[mid]) * 2 <= sm) {
                    right += stoneValue[mid];
                    --mid;
                }

                if (right * 2 == sm) {
                    dp[i][j] = mx[i][mid];
                }

                if (mid != i) {
                    dp[i][j] = max(dp[i][j], mx[i][mid - 1]);
                }

                if (mid != j) {
                    dp[i][j] = max(dp[i][j], mx[j][mid + 1]);
                }

                mx[i][j] = max(mx[i][j - 1], dp[i][j] + sm);
                mx[j][i] = max(mx[j][i + 1], dp[i][j] + sm);
            }
        }

        return dp[0][n - 1];
    }
};
