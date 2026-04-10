from collections import defaultdict
class Solution(object):
    def twoSum(self, nums, target):

        map=defaultdict(int)

        for i,val in enumerate(nums):
            difference=target - val 
            if difference in map:
                return [map[difference],i]
            else:
                map[val]=i
