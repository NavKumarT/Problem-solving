// Last updated: 8/29/2025, 9:53:13 PM
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
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;
        ListNode * curr = head;
        while(curr != nullptr && curr->next != nullptr){
            int temp = curr->val;
            curr->val = curr->next->val;
            curr->next->val = temp;
            curr = curr->next->next;
        }
        return head;
    }
};