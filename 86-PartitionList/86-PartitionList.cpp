// Last updated: 8/29/2025, 9:52:42 PM
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
    ListNode* partition(ListNode* head, int x) {
        if(head == nullptr || head->next == nullptr)
            return head;
        ListNode *dummy = new ListNode(-1);
        ListNode *dummyHead= dummy;
        ListNode *dummy2 = new ListNode(-1);
        ListNode *curr = head;
        ListNode *dummy2Head= dummy2;

        while(curr != nullptr){
            if(curr->val < x){
                dummy->next = curr;
                dummy = dummy->next; 
            } else {
                dummy2->next = curr;
                dummy2 = dummy2->next; 
            }
            curr = curr->next;
        }

        dummy->next = dummy2Head->next;
        dummy2->next = nullptr;
        return dummyHead->next;
    }
};