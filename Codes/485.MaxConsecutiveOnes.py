# Author - Hariharasudhan A
class Solution:
    def findMaxConsecutiveOnes(self, nums) :
        max_ones=0
        count=0
        for num in (nums): # traverse every element in nums
            if num==1: # ones may be ordered in any with zero as separator 
                count=count+1 # count number of ones
                max_ones= max(max_ones,count) #max_ones = max_ones if max_ones > count else count
            else:
                count=0
        return max_ones 
