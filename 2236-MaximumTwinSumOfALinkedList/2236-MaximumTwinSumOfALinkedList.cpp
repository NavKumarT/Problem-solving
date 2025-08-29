// Last updated: 8/29/2025, 9:48:31 PM
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
    int pairSum(ListNode* head) {
        // reverse the second half 
        // guaranteed to always have even number of nodes 
        ListNode *slow = head, *fast = head, *prev = nullptr;
        while(fast != NULL && fast->next != NULL){
            prev = slow;
            fast = fast->next->next;
            slow = slow->next;
        }
        // prev is the last node of the first half 
        if(prev != nullptr)
            prev->next = nullptr;

        // reverse the second half 
        ListNode *curr = slow, *next = nullptr;
        prev = nullptr;
        while(curr != nullptr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        // new head of the second half is slow;
        int ans = INT_MIN;
        while(prev != nullptr && head != nullptr){
            int currSum = prev->val + head->val;
            ans = max(currSum, ans);
            prev = prev->next;
            head = head->next;
        }
        return ans;
    }
};