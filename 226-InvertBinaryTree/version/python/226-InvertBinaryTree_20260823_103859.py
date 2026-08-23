# Last updated: 8/23/2026, 10:38:59 AM
1# Definition for a binary tree node.
2# class TreeNode:
3#     def __init__(self, val=0, left=None, right=None):
4#         self.val = val
5#         self.left = left
6#         self.right = right
7class Solution:
8    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
9        if root == None:
10            return root
11        temp = root.right
12        root.right = self.invertTree(root.left)
13        root.left = self.invertTree(temp)
14        return root