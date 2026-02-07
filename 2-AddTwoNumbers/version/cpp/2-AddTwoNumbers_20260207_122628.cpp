// Last updated: 2/7/2026, 12:26:28 PM
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
21            cout << val1 << " " << val2 << endl;
22            int sum = val1 + val2 + carry;
23            carry = sum >= 10 ? sum / 10 : 0;
24            sum = sum >= 10 ? sum % 10 : sum;
25
26            ListNode *node = new ListNode(sum);
27            if(!head)
28                head = node;
29            if(prev)
30                prev->next = node;
31            prev = node;
32            if(l1 != nullptr)
33                l1 = l1->next;
34            if(l2 != nullptr)
35                l2 = l2->next;
36        }
37        if(carry > 0)
38            prev->next = new ListNode(carry);
39        return head;
40
41    }
42
43    ListNode* reverse(ListNode* head){
44        ListNode *temp = head, *prev = nullptr, *next = nullptr;
45        while(temp != nullptr){
46            next = temp->next;
47            temp->next = prev;
48            prev = temp;
49            temp = next;
50        }
51        return prev;
52    }
53};