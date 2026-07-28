class Solution {
public:

    int isPalindrome(string &s , int l , int r){
        while(l < r){
            if(s[l] != s[r]){
                return 0;
            }
            l++;
            r--;
        }

        return 1;
    }

    string longestPalindrome(string s) {

        int n = s.length();
        int st = 0 , maxlen = 1;

        for(int i = 0 ; i < n ; i++){
            for(int j = i ; j < n ; j++){

                if(isPalindrome(s , i , j)){
                    if(j - i + 1 > maxlen){
                        maxlen = j - i + 1;
                        st = i;
                    }
                }
            }
        }

        return s.substr(st , maxlen);
    }
};
