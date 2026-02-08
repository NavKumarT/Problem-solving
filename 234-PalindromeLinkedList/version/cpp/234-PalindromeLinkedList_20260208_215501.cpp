// Last updated: 2/8/2026, 9:55:01 PM
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
13    bool isPalindrome(ListNode* head) {
14        // find the middle to divide the LL into 2 parts
15        if(head == nullptr || head->next == nullptr)
16            return true;
17        ListNode *fast = head, *slow = head, *prev = nullptr;
18        while(fast != nullptr && fast->next != nullptr){
19            fast = fast->next->next;
20            prev = slow;
21            slow = slow->next;
22        }
23        prev->next = nullptr;
24        ListNode *first = head, *second = slow;
25        second = reverse(second);
26        while(first != nullptr && second != nullptr){
27            if(first->val != second->val)
28                return false;
29            first = first->next;
30            second = second->next;
31        }
32        return true;
33        // reverse the second part of the LL 
34
35        // compare both
36    }
37
38    ListNode* reverse(ListNode* head){
39        ListNode *prev = nullptr, *next = nullptr, *temp = head;
40        while(temp != nullptr){
41            next = temp->next;
42            temp->next = prev;
43            prev = temp;
44            temp = next;
45        }
46        return prev;
47    }
48};