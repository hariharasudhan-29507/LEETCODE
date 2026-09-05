class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin() , nums.end());

        int len = nums.size(), product , max = 0 ;
        for(int i = 0 ; i < len ;i++){
            for(int j = i +1 ; j<len ; j++){
                product = (nums[i]-1)*(nums[j]-1);
                if(max < product){
                    max = product;
                }  
            }
        }

        return max;
    }
};
