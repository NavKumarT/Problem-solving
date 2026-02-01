// Last updated: 2/1/2026, 7:35:19 PM
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
13    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
14        if(list1 == nullptr)
15            return list2;
16        if(list2 == nullptr)
17            return list1;
18        ListNode* head = nullptr;
19        if(list1->val <= list2->val){
20            head = list1;
21            list1 = list1->next;
22        }
23        else {
24            head = list2;
25            list2 = list2->next;
26        }
27        ListNode* prev = head;
28        while(list1 != nullptr && list2 != nullptr){
29            if(list1->val <= list2->val){
30                prev->next = list1;
31                prev = list1;
32                list1 = list1->next;
33            } else {
34                prev->next = list2;
35                prev = list2;
36                list2 = list2->next;
37            }
38        }
39        if(list1 != nullptr)
40            prev->next = list1;
41        if(list2 != nullptr)
42            prev->next = list2;
43        return head;
44        
45    }
46};