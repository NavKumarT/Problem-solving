// Last updated: 8/29/2025, 9:48:26 PM
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
    ListNode* mergeNodes(ListNode* head) {
        int sum = 0;
        ListNode *newHead = nullptr, *newCurr = newHead;
        ListNode *curr = head;
        while(curr != nullptr){
            if(curr->val == 0){
                if(sum > 0){
                    ListNode *temp = new ListNode(sum);
                    if(newHead == nullptr){
                        newHead = temp;
                        newCurr = temp;
                    } else {
                        newCurr->next = temp;
                        newCurr = newCurr->next;
                    }
                    sum = 0;
                }
            } else {
                sum += curr->val;
            }
            curr = curr->next;
        }
        return newHead;
    }
};