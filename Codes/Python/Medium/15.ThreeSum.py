# Author - Hariharasudhan A
class Solution(object):
    def threeSum(self, nums):

        res=[]
        target=0
        nums.sort() # sorting them because we cant have duplicate sets 
        for i ,val in enumerate(nums): # traversing values along its position
            if i>0 and val==nums[i-1]: # if the current value is the same as its i-1 value on array
                continue
            l,r = i+1 ,len(nums)-1 # keeping left and right valus on the array 

            while l<r: 
                sum=val+nums[l]+nums[r] 
                '''
                traversing through every value on array using the outer for loop
                here we will find the sum up to target condtion using while  loop 
                '''
                if sum>target: # since we sorted the array , the largest elements are on the end of array
                    r-=1 
                elif sum < target: # smallest elements are on the start 
                    l+=1
                else:
                    res.append([val,nums[l],nums[r]]) # sum up to target values 
                    l+=1
            
        return res
