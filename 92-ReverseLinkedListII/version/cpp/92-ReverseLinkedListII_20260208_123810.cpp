// Last updated: 2/8/2026, 12:38:10 PM
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
13    ListNode* reverseBetween(ListNode* head, int left, int right) {
14        // UTILITY FUNCTION - {head, tail}
15        ListNode *next = nullptr, *prev = nullptr, *temp = head, *reverseHead;
16        int count = 1;
17        while(temp != nullptr){
18            if(count == left){
19                reverseHead = temp;
20            }
21            if(count < left){
22                prev = temp;
23            }
24            if(count == right){
25                next = temp->next;
26                break;
27            }
28            count++;
29            temp = temp->next;
30        }
31        cout << reverseHead->val << endl;
32        pair<ListNode*, ListNode*> p = reverse(reverseHead, next);
33        ListNode* reversedHead = p.first;
34        ListNode* reversedTail = p.second;
35        if(next != nullptr)
36            reversedTail->next = next;
37        if(prev == nullptr){
38            return reversedHead;
39        } else {
40            prev->next = reversedHead;
41            return head;
42        }
43        return head;
44    }
45
46    pair<ListNode*, ListNode*> reverse(ListNode* head, ListNode* stop){
47        ListNode *temp = head, *prev = nullptr, *next = nullptr, *tail = nullptr;
48        while(temp != stop){
49            if(!tail)
50                tail = temp;
51            next = temp->next;
52            temp->next = prev;
53            prev = temp;
54            temp = next;
55        }
56        cout << prev->val << " " << tail->val << endl;
57        return {prev, tail};
58    }
59};