# Last updated: 8/23/2026, 10:53:37 AM
1# Definition for a binary tree node.
2# class TreeNode:
3#     def __init__(self, val=0, left=None, right=None):
4#         self.val = val
5#         self.left = left
6#         self.right = right
7class Solution:
8    isBalancedTree = True
9    def isBalanced(self, root: Optional[TreeNode]) -> bool:
10        def depth(root):
11            if not root:
12                return 0
13            left = depth(root.left)
14            right = depth(root.right)
15            if abs(left-right) > 1:
16                self.isBalancedTree = False
17            return max(left, right) + 1
18        depth(root)
19        return self.isBalancedTree