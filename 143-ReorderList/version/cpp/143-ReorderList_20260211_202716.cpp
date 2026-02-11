// Last updated: 2/11/2026, 8:27:16 PM
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
13    void reorderList(ListNode* head) {
14        if(head == nullptr || head->next == nullptr)
15            return;
16        // find the middle of the linked list
17        ListNode *fast = head, *slow = head, *prev = nullptr;
18        while(fast != nullptr && fast->next != nullptr){
19            fast = fast->next->next;
20            prev = slow;
21            slow = slow->next;
22        }
23        ListNode *second = slow->next;
24        slow->next = nullptr;
25        second = reverse(second);
26        // reverse the second part 
27        ListNode *dummy = new ListNode(0);
28        ListNode *tail = dummy;
29        bool first = true;
30        while(head != nullptr && second != nullptr){
31            ListNode *next;
32            if(first){
33                next = head->next;
34                tail->next = head;
35                tail = tail->next;
36                tail->next = nullptr;
37                head = next;
38            } else {
39                next = second->next;
40                tail->next = second;
41                tail = tail->next;
42                tail->next = nullptr;
43                second = next;
44            }
45            first = !first;
46        }
47        ListNode* next;
48        while(head != nullptr){
49            next = head->next;
50            tail->next = head;
51            tail = tail->next;
52            tail->next = nullptr;
53            head = next;
54        }
55        while(second != nullptr){
56            next = second->next;
57            tail->next = second;
58            tail = tail->next;
59            tail->next = nullptr;
60            second = next;
61        } 
62        head = dummy->next;
63    }
64
65    ListNode* reverse(ListNode* head){
66        ListNode *curr = head, *next = nullptr, *prev = nullptr;
67        while(curr != nullptr){
68            next = curr->next;
69            curr->next = prev;
70            prev = curr;
71            curr = next;
72        }
73        return prev;
74    }
75};