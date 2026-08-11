class Solution(object):
    def getConcatenation(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        return nums+nums
s=Solution()
print(s.getConcatenation([1,2,1]))