// Last updated: 8/29/2025, 9:52:43 PM
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr)
            return head;
        ListNode *prev = head, *curr = head->next, *next = nullptr;
        while(curr != nullptr){
            if(curr->val == prev->val){
                // delete the node 
                next = curr->next;
                prev->next = next;
                curr = next;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};