class Solution {
public:
    bool checkDivisibility(int n) {
        int digitSum = 0;
        int digitProduct = 1;
        int temp = n;

        while (temp > 0) {
            int d = temp % 10;
            digitSum += d;
            digitProduct *= d;
            temp /= 10;
        }

        int divisor = digitSum + digitProduct;
        return n % divisor == 0;
    }
};
