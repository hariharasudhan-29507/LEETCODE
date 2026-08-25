class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int limit = nums.size();
        int res = nums.size();

        for(int i = 0 ; i < limit; i++){
            res ^= i ^ nums.at(i);
        }

        return res;
    }
};
