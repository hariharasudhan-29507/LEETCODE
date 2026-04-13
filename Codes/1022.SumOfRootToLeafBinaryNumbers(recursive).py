class TreeNode:
    def __init__(self,val=0,left=None,right=None):
        self.val=val
        self.left=left
        self.right=right
class Solution:
    def sumRootToLeaf(self,root,sum_val=0):
        if not root: return 0
        sum_val=sum_val*2+root.val
        if root.left or root.right:
            val1=self.sumRootToLeaf(root.left,sum_val)
            val2=self.sumRootToLeaf(root.right,sum_val)
            return val1+val2
        else:
            return sum_val
