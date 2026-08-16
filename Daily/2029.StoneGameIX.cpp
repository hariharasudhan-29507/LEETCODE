class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int c[3] = {0, 0, 0};
        for (int s : stones) {
            c[s % 3]++;
        }
        
        int c0 = c[0], c1 = c[1], c2 = c[2];
        
        if (c0 % 2 == 0) {
            return min(c1, c2) >= 1;
        } else {
            return abs(c1 - c2) >= 3;
        }
    }
};
