# Author Hariharasudhan A
class Solution(object):
    def getConcatenation(self, nums):
        # the array needs to be concatenated with the same array 
        '''
        this does the same thing 
        * def getConcatenation(self, nums):
              return nums + nums
        * def getConcatenation(self, nums):
              return nums * 2
           
        '''
        # traverse the given array and store it another
        nums1=[]
        for i in range (len(nums)):
            nums1.append(nums[i])
        # append the copy array elements 
        for i in nums1:
            nums.append(i)
        return nums
s=Solution()
print(s.getConcatenation([1,2,1]))
