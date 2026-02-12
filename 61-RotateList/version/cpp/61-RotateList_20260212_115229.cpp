// Last updated: 2/12/2026, 11:52:29 AM
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
13    ListNode* rotateRight(ListNode* head, int k) {
14        if(head == nullptr || head->next == nullptr)
15            return head;
16        ListNode *node = head;
17        int n = 0;
18        while(node != nullptr){
19            n++;
20            node = node->next;
21        }
22        k = k % n;
23
24        ListNode *fast = head, *slow = head, *next;
25        while(k > 0){
26            fast = fast->next;
27            k--;
28        }
29        while(fast != nullptr){
30            fast = fast->next;
31            next = slow;
32            slow = slow->next;
33        }
34        next->next = nullptr;
35        pair<ListNode*, ListNode*> p1 = reverse(slow);
36        pair<ListNode*, ListNode*> p2 = reverse(head);
37        // find the kth last node
38        p2.second->next = p1.first;
39        pair<ListNode*, ListNode*> p3 = reverse(p2.first);
40        return p3.first;
41        // reverse that part
42
43        // reverse the first part 
44
45        // reverse the whole linkedlist 
46    }
47
48    pair<ListNode*, ListNode*> reverse(ListNode* head){
49        ListNode *next, *prev = nullptr, *curr = head, *tail = nullptr;
50        while(curr){
51            if(!tail)
52                tail = curr;
53            next = curr->next;
54            curr->next = prev;
55            prev = curr;
56            curr = next;
57        }
58        return {prev, tail};
59
60    }
61};