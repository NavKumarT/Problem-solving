# Last updated: 8/10/2026, 7:57:08 PM
1# Definition for singly-linked list.
2# class ListNode:
3#     def __init__(self, val=0, next=None):
4#         self.val = val
5#         self.next = next
6class Solution:
7    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
8        slow, fast, prev = head, head, None
9        while n > 0 and fast != None:
10            fast = fast.next
11            n -= 1
12        while fast != None:
13            fast = fast.next
14            prev = slow
15            slow = slow.next
16        if prev == None:
17            return slow.next
18        prev.next = slow.next
19        return head
20        