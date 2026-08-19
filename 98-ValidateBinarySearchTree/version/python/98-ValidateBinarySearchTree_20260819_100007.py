# Last updated: 8/19/2026, 10:00:07 AM
1# Definition for a binary tree node.
2# class TreeNode:
3#     def __init__(self, val=0, left=None, right=None):
4#         self.val = val
5#         self.left = left
6#         self.right = right
7class Solution:
8    def isValidBST(self, root: Optional[TreeNode]) -> bool:
9        low, high = float('-inf'), float('inf')
10        def isValidBSTUtil(root: TreeNode, low: float, high: float):
11            if root == None:
12                return True
13            if root.val > low and root.val < high:
14                return isValidBSTUtil(root.left, low, root.val) and isValidBSTUtil(root.right, root.val, high)
15            else:
16                return False
17        return isValidBSTUtil(root, low, high)
18