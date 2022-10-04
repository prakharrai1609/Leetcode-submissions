# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def path_sum(self, root, targetSum) :
        if root == None:
            return False
        
        if root.left == None and root.right == None : 
            return targetSum == root.val
        
        op1 = self.path_sum(root.left, targetSum - root.val)
        op2 = self.path_sum(root.right, targetSum - root.val)
    
        return (op1 or op2)
    
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        return self.path_sum(root, targetSum)