class Solution {
public:
    int maxProduct(int n) {
        string temp = to_string(n);
        int len = temp.length();

        int product = 0;
        for (int i = 0; i < len; i++) {
            for (int j = i + 1; j < len; j++) {
                product = max(product, (temp[i] - '0') * (temp[j] - '0'));
            }
        }

        return product;
    }
};
