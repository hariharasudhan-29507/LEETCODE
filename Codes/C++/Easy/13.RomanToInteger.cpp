class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> numeral_set ={
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000} 
    };

        int len = s.length();
        int sum = 0;
        for(int i = 0 ; i<len;i++){
            if(i+1 < len && numeral_set[s[i]]<numeral_set[s[i+1]]){
                sum -= numeral_set[s[i]];
            }
            else{
                sum += numeral_set[s[i]];
            }
        }
        return sum;
    }
};
