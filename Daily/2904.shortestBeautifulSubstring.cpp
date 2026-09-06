class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        vector<int> ones;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '1') {
                ones.push_back(i);
            }
        }
        if (ones.size() < k) {
            return "";
        }
        int minLen = INT_MAX;
        string result = "";
        for (int i = 0; i <= (int)ones.size() - k; ++i) {
            int start = ones[i];
            int end = ones[i + k - 1];
            int len = end - start + 1;
            if (len < minLen) {
                minLen = len;
                result = s.substr(start, len);
            } else if (len == minLen) {
                string candidate = s.substr(start, len);
                if (candidate < result) {
                    result = candidate;
                }
            }
        }
        return result;
    }
};
