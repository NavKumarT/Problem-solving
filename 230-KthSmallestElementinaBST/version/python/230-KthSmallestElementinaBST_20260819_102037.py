# Last updated: 8/19/2026, 10:20:37 AM
1# Definition for a binary tree node.
2# class TreeNode:
3#     def __init__(self, val=0, left=None, right=None):
4#         self.val = val
5#         self.left = left
6#         self.right = right
7class Solution:
8    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
9        self.count = 0
10        self.kth_smallest = -1
11        def traversal(root):
12            if root == None:
13                return 
14            if root.left:
15                traversal(root.left)
16            self.count += 1
17            if self.count == k:
18                self.kth_smallest = root.val
19                return
20            if root.right:
21                traversal(root.right)
22        traversal(root)
23        return self.kth_smallest