class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> arr(26, 0);
        int n = s.length();
        
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            arr[ch - 'a']++;
        }
        
        string left = "";
        char mid = '\0';
        
        for (int i = 0; i < 26; i++) {
            if (arr[i] == 0) continue;
            
            char ch = 'a' + i;
            int count = arr[i];
            
            int half = count / 2;
            for (int j = 0; j < half; j++) {
                left += ch;
            }
            
            if (count % 2 == 1) {
                if (mid != '\0') {
                    return "";
                }
                mid = ch;
            }
        }
        
        string right = left;
        reverse(right.begin(), right.end());
        
        string res = left;
        if (mid != '\0') {
            res += mid;
        }
        res += right;
        
        return res;
    }
};
