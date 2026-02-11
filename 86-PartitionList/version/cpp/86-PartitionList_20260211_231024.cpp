// Last updated: 2/11/2026, 11:10:24 PM
1/**
2 * Definition for singly-linked list.
3 * struct ListNode {
4 *     int val;
5 *     ListNode *next;
6 *     ListNode() : val(0), next(nullptr) {}
7 *     ListNode(int x) : val(x), next(nullptr) {}
8 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
9 * };
10 */
11class Solution {
12public:
13    ListNode* partition(ListNode* head, int x) {
14        ListNode *less = new ListNode(0);
15        ListNode *more = new ListNode(0);
16        ListNode *moreDummy = more, *lessDummy = less;
17        ListNode *curr = head, *next;
18        while(curr != nullptr){
19            if(curr->val < x){
20                less->next = curr;
21                next = curr->next;
22                less = less->next;
23                less->next = nullptr;
24                curr = next;
25            } else {
26                more->next = curr;
27                next = curr->next;
28                more = more->next;
29                more->next = nullptr;
30                curr = next;
31            }
32        }
33        if(less){
34            less->next = moreDummy->next;
35            return lessDummy->next;
36        }
37        return moreDummy->next;
38    }
39};