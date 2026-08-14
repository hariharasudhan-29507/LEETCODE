class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        int totalOnes = 0;
        for (char c : s) {
            if (c == '1') totalOnes++;
        }

        vector<pair<char, int>> runs;
        for (int i = 0; i < n;) {
            int j = i;
            while (j < n && s[j] == s[i]) j++;
            runs.push_back({s[i], j - i});
            i = j;
        }

        int ans = totalOnes;

        for (int i = 0; i < runs.size(); i++) {
            if (runs[i].first != '1') continue;
            if (i == 0 || i == runs.size() - 1) continue;
            if (runs[i - 1].first != '0' || runs[i + 1].first != '0') continue;

            int left = runs[i - 1].second;
            int mid = runs[i].second;
            int right = runs[i + 1].second;

            ans = max(ans, totalOnes + left + right);
        }

        return ans;
    }
};
