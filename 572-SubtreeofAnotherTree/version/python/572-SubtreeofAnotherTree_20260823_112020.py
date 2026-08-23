# Last updated: 8/23/2026, 11:20:20 AM
1
2    
3# Definition for a binary tree node.
4# class TreeNode:
5#     def __init__(self, val=0, left=None, right=None):
6#         self.val = val
7#         self.left = left
8#         self.right = right
9class Solution:
10    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
11        def serializeTree(root, serializedString = ""):
12            if not root:
13                return serializedString + "(" + "#" + ")"
14            serializedString += "(" + str(root.val) + ")"
15            serializedString += serializeTree(root.left)
16            serializedString += serializeTree(root.right)
17            return serializedString
18        return serializeTree(root).find(serializeTree(subRoot)) != -1