class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum = nums.at(0);
        int n = nums.size();

        for(int i = 1 ; i < n; i++){
                if(nums.at(i) == nums.at(i-1)+1){
                    sum += nums.at(i) ;
                } 
                else{
                    break;
                }
        
        }

        unordered_set<int> sumset (nums.begin(), nums.end());

        while(sumset.count(sum)){
            sum++;
        }


        return sum;
    }
};
