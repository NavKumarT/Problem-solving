# Last updated: 8/22/2026, 5:57:50 PM
1# Definition for a binary tree node.
2# class TreeNode:
3#     def __init__(self, val=0, left=None, right=None):
4#         self.val = val
5#         self.left = left
6#         self.right = right
7class Solution:
8    def removeLeafNodes(self, root: Optional[TreeNode], target: int) -> Optional[TreeNode]:
9        # we will be doing a preorder traversal 
10        # make the subtree valid and then pass on the rep invariant 
11        if root == None:
12            return root
13        root.left = self.removeLeafNodes(root.left, target)
14        root.right = self.removeLeafNodes(root.right, target)
15        if root.val == target and root.left == None and root.right == None:
16            return None 
17        else:
18            return root
19        