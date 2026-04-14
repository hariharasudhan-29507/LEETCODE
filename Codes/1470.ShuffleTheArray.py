#Author - Hariharasudhan A
class Solution(object):
    def shuffle(self, nums, n):
        '''
        initialise a array with '0' with 2*n size 
        because 'n' is partition on nums to split 'nums' into parts of 'n'
        '''
        res_arr=[0 for x in range(2*n)]
        count=0
        '''
        index of nums goes as 0,1,2,3,4,5 the partition comes as [0,1,2] | [3,4,5]
        if n=3 
        i=0 | i+n = 3
        i=1 | i+n = 4
        i=2 | i+n = 5
        '''
        for i in range(n): # shuffle them accordingly as i , i+n
            res_arr[count] = nums[i]
            res_arr[count+1] = nums[i + n]
            count=count+2 
        return res_arr
