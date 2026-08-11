class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> res(2*n);

        int count = 0;
        for(int i = 0 ; i < n ; i++){
            res.at(count) = nums.at(i);
            res.at(count+1) = nums.at(i+n);

            count +=2;
        }

        return res;

    }
};