class Solution {
public:
    string addBinary(string a, string b) {
        int len1 = a.size() - 1;
        int len2 = b.size() - 1;
        int carry = 0;
        string res = "";

        while (len1 >= 0 || len2 >= 0 || carry) {
            int sum = carry;

            if (len1 >= 0){
                sum += a[len1--] - '0';
            }
            if (len2 >= 0){
                sum += b[len2--] - '0';
            }
            
           res = char(sum % 2 + '0') + res;
            carry = sum / 2;
        }

     
        return res;
    }
};
