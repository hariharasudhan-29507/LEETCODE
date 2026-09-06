class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int minIdx = 0, maxIdx = 0;
        
        for (int i = 1; i < n; ++i) {
            if (nums[i] < nums[minIdx]) minIdx = i;
            if (nums[i] > nums[maxIdx]) maxIdx = i;
        }
        
        int left = min(minIdx, maxIdx);
        int right = max(minIdx, maxIdx);
        
        return min({right + 1, n - left, (left + 1) + (n - right)});
    }
};
