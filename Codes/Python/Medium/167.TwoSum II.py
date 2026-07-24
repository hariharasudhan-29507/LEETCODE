# Author - Hariharasudhan A
class Solution(object):
    def twoSum(self, numbers, target):
        # keeping the left, right values on the array 
        l,r=0,len(numbers)-1
        
        while l<r:
            sum=numbers[l]+numbers[r] # checking sum up to values 
            if sum>target: # if sum is 12 , target is 9 ,then we can conclude that the values are large enough to omit
                r-=1
            elif sum<target: # if sum is 3 , target is 9 ,then we can conclude that the values are small enough to omit
                l+=1
            else:
                return [l+1,r+1]
        return []
