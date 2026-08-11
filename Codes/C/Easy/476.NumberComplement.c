class Solution {
public:
    void reverse(char* bin){
        int start = 0;
        int end = strlen(bin) - 1;
        char  temp;
        while (start < end) {
            temp = bin[start];
            bin[start] = bin[end];
            bin[end] = temp;
            start++;
            end--;
        }
    }

    void ToBinaryString(int num, char* bin_str) {
        int len;
        if (num == 0) {
            strcpy(bin_str, "0");
            return;
        }
        len = 0;
        while (num > 0) {
            bin_str[len++] = (num % 2) + '0';
            num /= 2;
        }
        bin_str[len] = '\0';
        reverse(bin_str);
    }

    int ToNumFromString(char* bin_str) {
        int res = 0;
        int len = strlen(bin_str);
        int i;                              
        for (i = 0; i < len; i++) {
            res = res * 2 + (bin_str[i] - '0');
        }
        return res;
    }

    int findComplement(int num) {
        char bin_str[64];
        int len;
        char comp_str[64];
        int i;                              
   
        ToBinaryString(num, bin_str);
   
        len = strlen(bin_str);
        for (i = 0; i < len; i++) {
            if (bin_str[i] == '1') {
                comp_str[i] = '0';
            } else {
                comp_str[i] = '1';
            }
        }
        comp_str[len] = '\0';
   
        return ToNumFromString(comp_str);
        }

};
