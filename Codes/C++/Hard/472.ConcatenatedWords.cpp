class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.size() < b.size();
        });
        
        unordered_set<string> dict;
        vector<string> ans;
        
        for (string& w : words) {
            if (w.empty()) continue;
            
            int n = w.size();
            vector<bool> dp(n + 1, false);
            dp[0] = true;
            
            for (int i = 1; i <= n; i++) {
                for (int j = 0; j < i; j++) {
                    if (dp[j] && dict.count(w.substr(j, i - j))) {
                        dp[i] = true;
                        break;
                    }
                }
            }
            
            if (dp[n]) {
                ans.push_back(w);
            }
            dict.insert(w);
        }
        
        return ans;
    }
};
