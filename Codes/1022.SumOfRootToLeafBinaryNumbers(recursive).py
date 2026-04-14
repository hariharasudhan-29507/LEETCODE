# class for node of the tree
class TreeNode:
    def __init__(self,val=0,left=None,right=None):
        self.val=val # value of the binary node
        self.left=left # left of the node
        self.right=right # right of the node
class Solution:
    def sumRootToLeaf(self,root,sum_val=0):
        if not root: return 0 # if root doesnot exist
        sum_val=sum_val*2+root.val  # binary to decimal conversion " 2^n + b(i) " , where b(i) is binary value , n is position of the i in binary number ,i=0 - n
        if root.left or root.right: # if left or right exists
            # sum every node and store it and find til leaf
            val1=self.sumRootToLeaf(root.left,sum_val) 
            val2=self.sumRootToLeaf(root.right,sum_val) 
            return val1+val2 # return intermediate sum value
        else:
            return sum_val # leaf sum
