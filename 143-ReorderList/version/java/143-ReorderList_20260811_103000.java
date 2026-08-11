// Last updated: 8/11/2026, 10:30:00 AM
1/**
2 * Definition for singly-linked list.
3 * public class ListNode {
4 *     int val;
5 *     ListNode next;
6 *     ListNode() {}
7 *     ListNode(int val) { this.val = val; }
8 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
9 * }
10 */
11class Solution {
12    public void reorderList(ListNode head) {
13        // find the middle
14        ListNode prev = null, fast = head, slow = head;
15        while(fast != null && fast.next != null){
16            fast = fast.next.next;
17            prev = slow;
18            slow = slow.next;
19        }
20        if(prev == null)
21            return;
22        // separate the first and second half 
23        prev.next = null;
24
25        // reverse the second half 
26        slow = reverseList(slow);
27
28        // merge the halves alternately
29        mergeTwoLists(head, slow);
30
31    }
32
33        public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
34        ListNode dummyHead = new ListNode(0), curr = dummyHead;
35        boolean first = true;
36        while(list1 != null && list2 != null){
37            if(first){
38                curr.next = list1;
39                curr = curr.next;
40                list1 = list1.next;
41            } else {
42                curr.next = list2;
43                curr = curr.next;
44                list2 = list2.next;
45            }
46            first = !first;
47        }
48        while(list1 != null){
49                curr.next = list1;
50                curr = curr.next;
51                list1 = list1.next;
52        }
53        while(list2 != null){
54            curr.next = list2;
55            curr = curr.next;
56            list2 = list2.next;
57        }
58        return dummyHead.next;        
59    }
60
61    private ListNode reverseList(ListNode head){
62        // reverses the list 
63        ListNode prev = null, curr = head, next;
64        while(curr != null){
65            next = curr.next;
66            curr.next = prev;
67            prev = curr;
68            curr = next;
69        }
70        return prev;
71    }
72}