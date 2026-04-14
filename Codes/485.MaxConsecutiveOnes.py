class Solution:
    def findMaxConsecutiveOnes(self, nums) :
        max_ones=0
        count=0
        for num in (nums):
            if num==1:
                count=count+1
                max_ones= max(max_ones,count) #max_ones = max_ones if max_ones > count else count
            else:
                count=0
        return max_ones
                
            

        
