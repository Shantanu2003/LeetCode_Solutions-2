# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def delNodes(self, root: Optional[TreeNode], to_delete: List[int]) -> List[TreeNode]:
        #s = set(to_delete)
        forest = []

        root = self.solve(root,to_delete,forest)

        if(root != None):
            forest.append(root)

        return forest

    def solve(self, root: Optional[TreeNode],s: List[int], forest: List[TreeNode]) -> TreeNode:
        if root == None:
            return None
        
        root.left = self.solve(root.left,s,forest)
        root.right = self.solve(root.right,s,forest)
        
        if root.val in s:

            if root.left:
                forest.append(root.left)
            if root.right:
                forest.append(root.right)
            
            return None
        
        return root

 

        