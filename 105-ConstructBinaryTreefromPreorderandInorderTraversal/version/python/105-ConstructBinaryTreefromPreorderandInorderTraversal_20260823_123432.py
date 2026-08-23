# Last updated: 8/23/2026, 12:34:32 PM
1# Definition for a binary tree node.
2# class TreeNode:
3#     def __init__(self, val=0, left=None, right=None):
4#         self.val = val
5#         self.left = left
6#         self.right = right
7class Solution:
8    preorderIndex = 0
9    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
10        left = 0
11        right = len(inorder)-1
12        def func(preorder, inorder, left , right):
13            if left > right or self.preorderIndex >= len(preorder):
14                return None 
15            root = TreeNode(preorder[self.preorderIndex])
16            self.preorderIndex += 1
17            idx = -1
18            for i in range(left, right+1):
19                if inorder[i] == root.val:
20                    idx = i
21                    break
22            
23            root.left = func(preorder, inorder, left,  idx-1)
24            root.right = func(preorder, inorder, idx+1, right)
25
26            return root
27        return func(preorder, inorder, left, right)
28