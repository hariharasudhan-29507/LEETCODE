class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        res=[]
        target=0
        nums.sort()
        for i ,val in enumerate(nums):
            if i>0 and val==nums[i-1]:
                continue
            l,r = i+1 ,len(nums)-1

            while l<r:
                sum=val+nums[l]+nums[r]
                if sum>target:
                    r-=1
                elif sum < target:
                    l+=1
                else:
                    res.append([val,nums[l],nums[r]])
                    l+=1
            
        return res
