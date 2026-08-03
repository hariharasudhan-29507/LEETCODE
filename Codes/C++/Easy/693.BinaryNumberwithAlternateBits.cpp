class Solution {
public:
    bool hasAlternatingBits(int n) {
        
        string binary = "";
        while(n>0){
            binary = char((n%2) + '0') + binary;
            n/=2;
        }
        bool res = true;

        for(int i = 1; i< binary.length();i++){
            if(binary[i]==binary[i-1] ){
                return false;
            }
        }
        return res;
    }
};
