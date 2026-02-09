// Last updated: 2/9/2026, 1:18:16 PM
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
13    ListNode* reverseKGroup(ListNode* head, int k) {
14        ListNode *curr = head, *n;
15        bool isFirst = true;
16        ListNode *prevFirst = nullptr;
17        while(curr != nullptr){
18            ListNode *temp = curr;
19            int available = 0;
20            while(temp != nullptr){
21                available++;
22                temp = temp->next;
23                if(available == k)
24                    break;
25            }
26            if(available < k){
27                prevFirst->next = curr;
28                 break;
29            }
30               
31            ListNode* first = curr;
32            ListNode *prev = nullptr, *next;
33            int count = 0;
34            while(curr != nullptr && count < k){
35                next = curr->next;
36                curr->next = prev;
37                prev = curr;
38                curr = next;
39                count++;
40            }
41            if(isFirst){
42                isFirst = false;
43                n = prev;
44            } else {
45                prevFirst->next = prev;
46            }
47            prevFirst = first;
48        }
49        return n;
50    }
51};