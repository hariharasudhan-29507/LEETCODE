class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        vector<int> cnt(26, 0);
        for (char c : s) {
            cnt[c - 'a']++;
        }
        string ans = "";
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            int t = target[i] - 'a';
            for (int j = t + 1; j < 26; ++j) {
                if (cnt[j] > 0) {
                    string cur = target.substr(0, i);
                    cur.push_back('a' + j);
                    cnt[j]--;
                    for (int k = 0; k < 26; ++k) {
                        if (cnt[k] > 0) {
                            cur.append(cnt[k], 'a' + k);
                        }
                    }
                    cnt[j]++;
                    ans = cur;
                    break;
                }
            }
            if (cnt[t] == 0) {
                break;
            }
            cnt[t]--;
        }
        return ans;
    }
};
