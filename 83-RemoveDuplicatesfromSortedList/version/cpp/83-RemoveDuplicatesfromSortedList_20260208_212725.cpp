// Last updated: 2/8/2026, 9:27:25 PM
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
14        if(!head)
15            return head;
16        ListNode *prev = head, *temp = head->next;
17        while(temp != nullptr){
18            if(prev->val == temp->val){
19                temp = temp->next;
20                continue;
21            } else {
22                prev->next = temp;
23                prev = temp;
24                temp = temp->next;
25            }
26        }
27        prev->next = nullptr;
28        return head;
29    }
30};