# Last updated: 8/23/2026, 11:08:51 AM
1# Definition for a binary tree node.
2# class TreeNode:
3#     def __init__(self, val=0, left=None, right=None):
4#         self.val = val
5#         self.left = left
6#         self.right = right
7class Solution:
8    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
9        def serializeTree(root, serializedString = ""):
10            if not root:
11                return serializedString + "(" + "#" + ")" + "-"
12            serializedString += "(" + str(root.val) + ")" + "-"
13            serializedString += serializeTree(root.left)
14            serializedString += serializeTree(root.right)
15            return serializedString
16        print(serializeTree(p))
17        print(serializeTree(q))
18        return serializeTree(p) == serializeTree(q)