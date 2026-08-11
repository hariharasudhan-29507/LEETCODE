class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum = nums.at(0);
        int res = 0;
        int n = nums.size();

        for(int i = 1 ; i < n; i++){
                if(nums.at(i) == nums.at(i-1)+1){
                    sum += nums.at(i) ;
                } 
                else{
                    break;
                }
        
        }

        int flag = 1;
        while(flag){
            flag = 0;
            for(int num : nums){
            if(sum == num and flag == 0){
                sum++;
                flag = 1;
            }
        }
        }

        return sum;
    }
};
