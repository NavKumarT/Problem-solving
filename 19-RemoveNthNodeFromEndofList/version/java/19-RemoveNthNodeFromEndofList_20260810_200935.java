// Last updated: 8/10/2026, 8:09:35 PM
1class Solution {
2    public ListNode removeNthFromEnd(ListNode head, int n) {
3        ListNode slow = head;
4        ListNode prev = null;
5        ListNode fast = head;
6        while(n > 0 && fast != null){
7            n--;
8            fast = fast.next;
9        }
10        
11        while(fast != null){
12            fast = fast.next;
13            prev = slow;
14            slow = slow.next;
15        }
16        
17        if (prev == null){
18            return slow.next;
19        }
20        prev.next = slow.next;
21        return head;
22    }
23}