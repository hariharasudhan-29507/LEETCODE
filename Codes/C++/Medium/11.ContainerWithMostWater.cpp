class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int left = 0 , right = height.size()-1 , result =0 ;

        while(left <  right){
            int width = right - left;
            int minimum_height = min(height[left] , height[right]);
            int area = width*minimum_height;
            result = max(result , area);
        
            if(height[left] < height[right]){
                left++;
            }
            else{
                right--;
            }
            
        }
        return result;
    }
   
};
