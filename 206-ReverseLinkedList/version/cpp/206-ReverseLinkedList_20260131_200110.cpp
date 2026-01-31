// Last updated: 1/31/2026, 8:01:10 PM
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
13    ListNode* reverseList(ListNode* head) {
14        ListNode *temp = nullptr, *curr = head, *prev = nullptr, *next = nullptr;
15        while(curr != nullptr){
16            next = curr->next;
17            curr->next = prev;
18            prev = curr;
19            curr = next;
20        }
21        return prev;
22    }
23};