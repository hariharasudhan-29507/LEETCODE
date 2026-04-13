class Solution(object):
    def shuffle(self, nums, n):
        """
        :type nums: List[int]
        :type n: int
        :rtype: List[int]
        """
        res_arr=[0 for x in range(2*n)]
        count=0
        for i in range(n):
            res_arr[count] = nums[i]
            res_arr[count+1] = nums[i + n]
            count=count+2
        return res_arr
