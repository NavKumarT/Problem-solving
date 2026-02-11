// Last updated: 2/11/2026, 10:58:23 AM
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
13    ListNode* deleteDuplicates(ListNode* head) {
14        ListNode *prev  = head, *newHead = nullptr, *temp = head, *newTail = nullptr;
15        int count = 1;
16        while(temp != nullptr){
17            ListNode *next = temp->next;
18            while(next != nullptr && temp->val == next->val){
19                next = next->next;
20                count++;
21            }
22            if(count == 1){
23                if(newHead == nullptr){
24                    newHead = temp;
25                    newTail = temp;
26                    newTail->next = nullptr;
27                } else {
28                    newTail->next = temp;
29                    newTail = temp;
30                    newTail->next = nullptr;
31                }
32            }
33            temp = next;
34            count = 1;
35        }
36        return newHead;
37    }
38};