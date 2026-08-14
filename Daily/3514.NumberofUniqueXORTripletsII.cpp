class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        
        int n = nums.size();
        int maxELT = *max_element(begin(nums),end(nums));
        int power = 1 , count = 1;

        while(power <= maxELT){
            power <<= 1;
        }
        
        vector<bool> XORpairs(power , false);
        vector<bool> XORtrips(power , false);

        for(int i = 0 ; i < n ;i++){
            for(int j = i ; j < n ; j++){
                XORpairs[nums[i] ^ nums[j]] = true;
            }
        }

        for(int i = 0 ; i < power ; i++){
            if (XORpairs[i] == true ){
                for(int &num : nums ){
                    XORtrips[i ^ num] = true;
                }
            }
        }

        for(int i = 0 ; i < power ;i++){
            if( XORtrips[i] == true) count++;
        }

        return count-1;
    }

};
