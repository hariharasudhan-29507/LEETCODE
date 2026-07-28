class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        vector <int> hashtable (256 , -1);
        int n = s.length();
        int l = 0 , r = 0 , maxlen = 0;

        while (r < n){
            if ((hashtable[s[r]] != -1) && (hashtable[s[r]] >= l)){
                l = hashtable[s[r]] + 1;                
            } 
            int len = r - l + 1;
            if(maxlen < len){
                maxlen = len ;
            }
            hashtable[s[r]] = r;
            r++;
        }

        return maxlen;
    }
};
