class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = (int)s.size();
        vector<int> cnt(26, 0);
        for (char ch : s) cnt[ch - 'a']++;

        int oddCnt = 0;
        char oddChar = 0;
        for (int i = 0; i < 26; ++i) {
            if (cnt[i] % 2) {
                oddCnt++;
                oddChar = 'a' + i;
            }
        }
        if (oddCnt > 1) return "";

        int m = n / 2;
        string mid = (n % 2 == 1) ? string(1, oddChar) : "";
        vector<int> half(26);
        for (int i = 0; i < 26; ++i) half[i] = cnt[i] / 2;

        string pref = target.substr(0, m);
        vector<int> rem = half;
        int fail = -1;

        for (int i = 0; i < m; ++i) {
            int c = pref[i] - 'a';
            rem[c]--;
            if (rem[c] < 0) {
                fail = i;
                rem[c]++;
                break;
            }
        }

        auto buildPal = [&](const string& left) -> string {
            string right = left;
            reverse(right.begin(), right.end());
            if (n % 2 == 0) return left + right;
            return left + mid + right;
        };

        auto isGreater = [&](const string& left) -> bool {
            if (n % 2 == 0) {
                string rev = left;
                reverse(rev.begin(), rev.end());
                return rev > target.substr(m);
            } else {
                if (mid[0] > target[m]) return true;
                if (mid[0] < target[m]) return false;
                string rev = left;
                reverse(rev.begin(), rev.end());
                return rev > target.substr(m + 1);
            }
        };

        if (fail == -1) {
            if (isGreater(pref)) return buildPal(pref);

            for (int k = m - 1; k >= 0; --k) {
                int c = pref[k] - 'a';
                rem[c]++;
                for (int d = c + 1; d < 26; ++d) {
                    if (rem[d] > 0) {
                        rem[d]--;
                        string suffix;
                        for (int x = 0; x < 26; ++x)
                            suffix += string(rem[x], 'a' + x);
                        string left = pref.substr(0, k) + char('a' + d) + suffix;
                        return buildPal(left);
                    }
                }
            }
            return "";
        }

        int c = pref[fail] - 'a';
        for (int d = c + 1; d < 26; ++d) {
            if (rem[d] > 0) {
                rem[d]--;
                string suffix;
                for (int x = 0; x < 26; ++x)
                    suffix += string(rem[x], 'a' + x);
                string left = pref.substr(0, fail) + char('a' + d) + suffix;
                return buildPal(left);
            }
        }

        for (int k = fail - 1; k >= 0; --k) {
            int c = pref[k] - 'a';
            rem[c]++;
            for (int d = c + 1; d < 26; ++d) {
                if (rem[d] > 0) {
                    rem[d]--;
                    string suffix;
                    for (int x = 0; x < 26; ++x)
                        suffix += string(rem[x], 'a' + x);
                    string left = pref.substr(0, k) + char('a' + d) + suffix;
                    return buildPal(left);
                }
            }
        }

        return "";
    }
};
