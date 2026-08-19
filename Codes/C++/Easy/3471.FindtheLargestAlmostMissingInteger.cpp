class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        if (k == n) return *max_element(nums.begin(), nums.end());
        vector<int> cnt(51);
        for (int x : nums) ++cnt[x];
        if (k == 1) {
            int ans = -1;
            for (int x : nums) if (cnt[x] == 1) ans = max(ans, x);
            return ans;
        }
        int ans = -1;
        if (cnt[nums[0]] == 1) ans = max(ans, nums[0]);
        if (cnt[nums[n - 1]] == 1) ans = max(ans, nums[n - 1]);
        return ans;
    }
};
