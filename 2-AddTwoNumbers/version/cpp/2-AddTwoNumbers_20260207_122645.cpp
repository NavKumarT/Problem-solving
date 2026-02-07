// Last updated: 2/7/2026, 12:26:45 PM
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
13    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
14        int carry = 0;
15        ListNode *head = nullptr, *prev = nullptr;
16        // l1 = reverse(l1);
17        // l2 = reverse(l2);
18        while(l1 != nullptr || l2 != nullptr){
19            int val1 = l1 == nullptr ? 0 : l1->val;
20            int val2 = l2 == nullptr ? 0 : l2->val;
21            int sum = val1 + val2 + carry;
22            carry = sum >= 10 ? sum / 10 : 0;
23            sum = sum >= 10 ? sum % 10 : sum;
24
25            ListNode *node = new ListNode(sum);
26            if(!head)
27                head = node;
28            if(prev)
29                prev->next = node;
30            prev = node;
31            if(l1 != nullptr)
32                l1 = l1->next;
33            if(l2 != nullptr)
34                l2 = l2->next;
35        }
36        if(carry > 0)
37            prev->next = new ListNode(carry);
38        return head;
39
40    }
41
42    ListNode* reverse(ListNode* head){
43        ListNode *temp = head, *prev = nullptr, *next = nullptr;
44        while(temp != nullptr){
45            next = temp->next;
46            temp->next = prev;
47            prev = temp;
48            temp = next;
49        }
50        return prev;
51    }
52};