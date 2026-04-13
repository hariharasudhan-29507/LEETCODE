class Solution(object):
    def fetchIndex(self,nums,target):
        for i,val in enumerate(nums):
            if val==target:
                return i
    def searchInsert(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        if target in nums:
            return self.fetchIndex(nums,target)
        else:
            nums.append(target)
            nums.sort()
            return self.fetchIndex(nums,target)
