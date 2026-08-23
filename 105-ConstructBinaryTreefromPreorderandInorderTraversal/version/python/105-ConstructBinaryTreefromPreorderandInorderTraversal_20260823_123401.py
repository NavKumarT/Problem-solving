# Last updated: 8/23/2026, 12:34:01 PM
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
13            if left > right:
14                return None 
15            if self.preorderIndex >= len(preorder):
16                return None
17            root = TreeNode(preorder[self.preorderIndex])
18
19            self.preorderIndex += 1
20
21            # get the index in inorder
22
23            idx = -1
24            for i in range(left, right+1):
25                if inorder[i] == root.val:
26                    idx = i
27                    break
28            
29            root.left = func(preorder, inorder, left,  idx-1)
30            root.right = func(preorder, inorder, idx+1, right)
31
32            return root
33        return func(preorder, inorder, left, right)
34