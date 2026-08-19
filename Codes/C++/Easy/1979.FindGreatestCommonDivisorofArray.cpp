class Solution {
public:
    int findGCD(vector<int>& nums) {
        for(int k = 0 ; k < nums.size() ; k++){
            for(int i = 0 ;i<nums.size() - 1;i++){
                if (nums.at(i) > nums.at(i+1)){
                    int temp = nums[i+1];
                    nums[i+1] = nums[i];
                    nums[i] = temp;
                }
            }
        }

        int num1 = nums[0];
        int num2 = nums[nums.size()-1];

        while(num2!=0){
            int rem = num1%num2;
            num1 = num2;
            num2 = rem; 
        }
        return num1;
    }
};
