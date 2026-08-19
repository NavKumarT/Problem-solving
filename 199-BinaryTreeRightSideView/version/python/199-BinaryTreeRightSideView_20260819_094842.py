# Last updated: 8/19/2026, 9:48:42 AM
1# Definition for a binary tree node.
2# class TreeNode:
3#     def __init__(self, val=0, left=None, right=None):
4#         self.val = val
5#         self.left = left
6#         self.right = right
7class Solution:
8    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
9        output = []
10        queue = deque()
11        if root == None:
12            return output
13        queue.append(root)
14        while len(queue) > 0:
15            n = len(queue)
16            last_element = -1
17            while n > 0:
18                node = queue.popleft()
19                if node.left:
20                    queue.append(node.left)
21                if node.right:
22                    queue.append(node.right)
23                if n == 1:
24                    last_element = node.val
25                n -= 1
26            output.append(last_element)
27        return output