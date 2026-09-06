class Solution {
public:
    int numDistinct(string s, string t) {
        int n = t.size();
        vector<int> dp(n + 1);
        dp[0] = 1;
        for (char c : s) {
            for (int j = n; j >= 1; --j) {
                if (c == t[j - 1]) {
                    if (dp[j] <= INT_MAX - dp[j - 1]) {
                        dp[j] += dp[j - 1];
                    } else {
                        dp[j] = INT_MAX;
                    }
                }
            }
        }
        return dp[n];
    }
};
