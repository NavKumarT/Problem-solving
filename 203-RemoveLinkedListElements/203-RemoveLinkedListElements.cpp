// Last updated: 8/29/2025, 9:51:27 PM
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *next = nullptr;
        while(head != NULL && head->val == val){
            next = head->next;
            delete head;
            head = next;
        }
        ListNode *prev = head, *curr = head;
        while(curr != NULL){
            if(curr->val == val){
                next = curr->next;
                prev->next = next;
                delete curr;
                curr = next;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};