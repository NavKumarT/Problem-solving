// Last updated: 2/12/2026, 4:27:01 PM
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
13    ListNode* swapPairs(ListNode* head) {
14        if(head == nullptr || head->next == nullptr)
15            return head;
16        ListNode *curr = head, *newHead = nullptr, *prev = nullptr, *next;
17        while(curr != nullptr && curr->next != nullptr){
18            next = curr->next->next;
19            ListNode *temp = curr;
20            curr = curr->next;
21            curr->next = temp;
22            temp->next = nullptr;
23            if(!newHead)
24                newHead = curr;
25            if(prev){
26                prev->next = curr;
27            }
28            prev = temp;
29            curr = next;
30        }
31        if(curr){
32            prev->next = curr;
33            curr->next = nullptr;
34        }
35        return newHead;  
36    }
37};