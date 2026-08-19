# Last updated: 8/19/2026, 9:41:31 AM
1# Definition for a binary tree node.
2# class TreeNode:
3#     def __init__(self, val=0, left=None, right=None):
4#         self.val = val
5#         self.left = left
6#         self.right = right
7class Solution:
8    def insertIntoBST(self, root: Optional[TreeNode], val: int) -> Optional[TreeNode]:
9        if root == None:
10            return TreeNode(val)
11        elif root.val > val:
12            root.left = self.insertIntoBST(root.left, val)
13        else: 
14            root.right = self.insertIntoBST(root.right, val)
15        return root