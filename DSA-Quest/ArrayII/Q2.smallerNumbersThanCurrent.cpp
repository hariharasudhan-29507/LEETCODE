class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        unordered_map<int, int> smallerCount;
        for (int i = 0; i < (int)sorted.size(); ++i) {
            if (smallerCount.find(sorted[i]) == smallerCount.end()) {
                smallerCount[sorted[i]] = i;
            }
        }

        vector<int> ans;
        ans.reserve(nums.size());
        for (int x : nums) {
            ans.push_back(smallerCount[x]);
        }
        return ans;
    }
};
