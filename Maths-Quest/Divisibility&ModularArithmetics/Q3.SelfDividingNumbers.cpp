class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        for (int x = left; x <= right; ++x) {
            int n = x;
            bool valid = true;
            while (n > 0) {
                int d = n % 10;
                if (d == 0 || x % d != 0) {
                    valid = false;
                    break;
                }
                n /= 10;
            }
            if (valid) res.push_back(x);
        }
        return res;
    }
};
