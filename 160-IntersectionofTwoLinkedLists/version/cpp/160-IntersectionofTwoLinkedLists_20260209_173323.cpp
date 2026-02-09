// Last updated: 2/9/2026, 5:33:23 PM
1/**
2 * Definition for singly-linked list.
3 * struct ListNode {
4 *     int val;
5 *     ListNode *next;
6 *     ListNode(int x) : val(x), next(NULL) {}
7 * };
8 */
9class Solution {
10public:
11    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
12        int m  = 0, n = 0;
13        ListNode *currA = headA, *currB = headB;
14        while(currA != nullptr){
15            m++;
16            currA = currA->next;
17        } 
18        while(currB != nullptr){
19            n++;
20            currB = currB->next;
21        }
22        int difference = abs(m-n);
23        currA = headA, currB = headB;
24        if(m > n){
25            while(difference > 0){
26                currA = currA->next;
27                difference--;
28            }
29        } else {
30            while(difference > 0){
31                currB = currB->next;
32                difference--;
33            }
34        }
35        while(currA != nullptr && currB != nullptr){
36            if(currA == currB)
37                return currA;
38            currA = currA->next;
39            currB = currB->next;
40        }
41        return nullptr;
42    }
43};