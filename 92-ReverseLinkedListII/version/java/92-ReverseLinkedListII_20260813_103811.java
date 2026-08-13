// Last updated: 8/13/2026, 10:38:11 AM
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
12    public ListNode reverseBetween(ListNode head, int leftN, int rightN) {
13        if(leftN == rightN)
14            return head;
15        ListNode prev = null, curr = head, subHead = null, subTail = null;
16        ListNode left = null, right = null;
17        int count = 1;
18        while(curr != null){
19            if(count == leftN){
20                subHead = curr;
21                left = prev;
22            } else if(count == rightN){
23                subTail = curr;
24                right = curr.next;
25                break;
26            }
27            prev = curr;
28            curr = curr.next;
29            count++;
30        }
31        subTail.next = null;
32        if(left != null) left.next = null;
33        List<ListNode> listEnds = reverseList(subHead);
34        subHead = listEnds.get(0);
35        subTail = listEnds.get(1);
36        subTail.next = right;
37
38        if(left != null)
39            left.next = subHead;
40        else 
41            return subHead;
42        return head;
43    }
44
45    public List<ListNode> reverseList(ListNode head){
46        ListNode next = null, prev = null, curr = head, newTail = null;
47        while(curr != null){
48            next = curr.next;
49            curr.next = prev;
50            prev = curr;
51            if(newTail == null)
52                newTail = curr;
53            curr = next;
54        }
55        return List.of(prev, newTail);
56    }
57}