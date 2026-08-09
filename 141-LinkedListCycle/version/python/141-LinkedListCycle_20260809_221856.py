# Last updated: 8/9/2026, 10:18:56 PM
1# Definition for singly-linked list.
2# class ListNode:
3#     def __init__(self, x):
4#         self.val = x
5#         self.next = None
6
7class Solution:
8    def hasCycle(self, head: Optional[ListNode]) -> bool:
9        slow, fast = head, head
10        while fast != None and fast.next != None:
11            fast = fast.next.next
12            slow = slow.next
13            if slow == fast:
14                return True
15        return False