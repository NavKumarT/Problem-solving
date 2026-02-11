// Last updated: 2/11/2026, 7:31:49 PM
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
13    ListNode* oddEvenList(ListNode* head) {
14        ListNode *evenDummy = new ListNode(0);
15        ListNode *oddDummy = new ListNode(0);
16        ListNode *evenTail = evenDummy, *oddTail = oddDummy;
17        ListNode *temp = head;
18        bool odd = true;
19        while(temp != nullptr){
20            ListNode *next = temp->next;
21            if(!odd){
22                evenTail->next = temp;
23                evenTail = evenTail->next;
24                evenTail->next = nullptr;
25                odd = !odd;
26            } else {
27                oddTail->next = temp;
28                oddTail = oddTail->next;
29                oddTail->next = nullptr;
30                odd = !odd;
31            }
32            temp = next;
33        }
34        if(oddTail == nullptr)
35            return evenDummy->next;
36        oddTail->next = evenDummy->next;
37        return oddDummy->next;
38    }
39};