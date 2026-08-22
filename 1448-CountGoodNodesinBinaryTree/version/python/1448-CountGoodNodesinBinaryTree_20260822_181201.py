# Last updated: 8/22/2026, 6:12:01 PM
1# Definition for a binary tree node.
2# class TreeNode:
3#     def __init__(self, val=0, left=None, right=None):
4#         self.val = val
5#         self.left = left
6#         self.right = right
7class Solution:
8    count = 0
9
10
11    def goodNodes(self, root: TreeNode) -> int:
12        def traversal(root: TreeNode, greatest = int):
13            if root == None:
14                return
15            if root.val >= greatest:
16                self.count += 1
17                greatest = max(greatest, root.val)
18            traversal(root.left, greatest)
19            traversal(root.right, greatest)
20        traversal(root, float('-inf'))
21        return self.count