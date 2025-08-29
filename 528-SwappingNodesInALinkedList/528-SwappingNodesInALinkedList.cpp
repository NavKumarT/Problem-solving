// Last updated: 8/29/2025, 9:50:35 PM
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
    ListNode* swapNodes(ListNode* head, int k) {
        if(head == NULL || head->next == NULL)
            return head;
        int count = 1;
        ListNode* curr = head;
        while(count < k){
            curr = curr->next;
            count++;
        }
           ListNode* first = curr;
        count = 1;
        curr = head;
        while(count <= k){
            count++;
            curr = curr->next;
        }

        ListNode* second = head;
        while(curr != NULL){
            curr = curr->next;
            second = second->next;
        }
        int temp = second->val;
        second->val = first->val;
        first->val = temp;
        return head;
    }
};