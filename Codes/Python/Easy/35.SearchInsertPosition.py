# Author - Hariharasudhan A
class Solution(object):
    def fetchIndex(self,nums,target):
        for i,val in enumerate(nums): # traverse through values along with index 
            if val==target: # if target locked then return index
                return i
    def searchInsert(self, nums, target):
        if target in nums: # if target already exists then fetch index
            return self.fetchIndex(nums,target)
        else: # if not then add it - sort it - then fetch index
            nums.append(target)
            nums.sort()
            return self.fetchIndex(nums,target)
