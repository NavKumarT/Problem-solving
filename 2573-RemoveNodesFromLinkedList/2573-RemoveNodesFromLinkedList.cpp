// Last updated: 8/29/2025, 9:48:11 PM
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        ListNode *reversedHead = reverseLL(head);
        int maximum = INT_MIN;
        ListNode *curr = reversedHead, *prev = nullptr, *next = nullptr;
        while(curr != nullptr){
            if(curr->val >= maximum){
                prev = curr;
                maximum = max(maximum, curr->val);
                curr = curr->next;
            } else {
                prev->next = curr->next;
                curr = prev->next;
            }
        }
        curr = reversedHead;
        ListNode *ans =  reverseLL(reversedHead);
        return ans;
    }

    ListNode* reverseLL(ListNode* head){
        ListNode *curr = head, *prev = nullptr, *next;
        while(curr != nullptr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};