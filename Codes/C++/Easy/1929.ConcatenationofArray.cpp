class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int len = nums.size();
        
        vector<int> nums1 = nums;
        for(int &num : nums){
            nums1.emplace_back(num);
        }

        return nums1;
    }
};
