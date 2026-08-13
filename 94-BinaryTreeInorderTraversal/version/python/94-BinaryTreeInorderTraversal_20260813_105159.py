# Last updated: 8/13/2026, 10:51:59 AM
1# Definition for a binary tree node.
2# class TreeNode:
3#     def __init__(self, val=0, left=None, right=None):
4#         self.val = val
5#         self.left = left
6#         self.right = right
7class Solution:
8    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
9        traversal = []
10        def traversalUtils(root):
11            if root == None:
12                return
13            traversalUtils(root.left)
14            traversal.append(root.val)
15            traversalUtils(root.right)
16        traversalUtils(root)
17        return traversal
18        