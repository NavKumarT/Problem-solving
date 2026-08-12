// Last updated: 8/12/2026, 11:01:39 AM
1class Solution {
2    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
3        ListNode dummyHead = new ListNode(0);
4        dummyHead.next = l1;
5        ListNode prev = dummyHead;
6        int carry = 0;
7        while(l1 != null && l2 != null) {
8            int sum = l1.val + l2.val + carry;
9            
10            carry = sum / 10;
11            sum = sum % 10;
12            l1.val = sum;
13            prev = l1;
14            l1 = l1.next;
15            l2 = l2.next;
16        }
17        while(l1 != null) {
18            int sum = l1.val + carry;
19            carry = sum / 10;
20            sum = sum % 10;
21            l1.val = sum;
22            prev = l1;
23            l1 = l1.next;
24        }
25        while(l2 != null) {
26            int sum = l2.val + carry;
27            carry = sum / 10;
28            sum = sum % 10;
29//            l2.val = sum;
30            prev.next = new ListNode(sum);
31            prev = prev.next;
32            l2 = l2.next;
33        }
34        
35        if(carry > 0){
36            prev.next = new ListNode(carry);
37        }
38        
39        return dummyHead.next;
40        
41        
42    }
43}