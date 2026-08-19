class Solution {
public:
    int smallestNumber(int n, int t) {
        while (true) {
            int x = n;
            long long prod = 1;
            while (x > 0) {
                prod *= (x % 10);
                x /= 10;
            }
            if (prod % t == 0) {
                return n;
            }
            ++n;
        }
        return -1; 
    }
};
