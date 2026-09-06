class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++) {
            v.emplace_back(nums[i], i);
        }
        sort(v.begin(), v.end());
        
        vector<int> res(n);
        int i = 0;
        while (i < n) {
            int j = i;
            vector<int> idx;
            vector<int> val;
            while (j < n && (j == i || v[j].first - v[j - 1].first <= limit)) {
                idx.push_back(v[j].second);
                val.push_back(v[j].first);
                j++;
            }
            sort(idx.begin(), idx.end());
            for (int k = 0; k < (int)idx.size(); k++) {
                res[idx[k]] = val[k];
            }
            i = j;
        }
        return res;
    }
};
