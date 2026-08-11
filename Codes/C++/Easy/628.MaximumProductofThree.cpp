class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int sum1 , sum2 ,len = nums.size() -1  ;
        sum1 = nums.at(len) * nums.at(len-1) * nums.at(len-2);
        sum2 = nums.at(0) * nums.at(1) * nums.at(len);

        if(sum1 > sum2){
            return sum1;
        }
        else{
            return sum2;
        }
    }
};
