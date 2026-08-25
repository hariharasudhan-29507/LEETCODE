class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        for(int i = 1 ; ; i++){
            if(!std::ranges::contains(nums ,i*k )){
                return i*k;
            }
        }
    }
};
