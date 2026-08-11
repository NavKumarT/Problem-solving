// Last updated: 8/11/2026, 10:21:18 AM
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
12    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
13        ListNode dummyHead = new ListNode(0), curr = dummyHead;
14        while(list1 != null && list2 != null){
15            if(list1.val <= list2.val){
16                curr.next = list1;
17                curr = curr.next;
18                list1 = list1.next;
19            } else {
20                curr.next = list2;
21                curr = curr.next;
22                list2 = list2.next;
23            }
24        }
25        while(list1 != null){
26                curr.next = list1;
27                curr = curr.next;
28                list1 = list1.next;
29        }
30        while(list2 != null){
31            curr.next = list2;
32            curr = curr.next;
33            list2 = list2.next;
34        }
35        return dummyHead.next;        
36    }
37}