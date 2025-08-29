// Last updated: 8/29/2025, 9:52:44 PM
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
        unordered_map<int, int> mp;
        ListNode *curr = head;
        while(curr != nullptr){
            mp[curr->val]++;
            curr = curr->next;
        }

        curr = head;
        ListNode* newHead = nullptr;
        ListNode *prev = nullptr;
        while(curr != nullptr){
            if(mp[curr->val] > 1){
                ListNode *next = curr->next;
                delete curr;
                curr = next;
            } else {
                if(prev != nullptr){
                    prev->next = curr;
                    prev = curr;
                } else {
                    newHead = curr;
                    prev = curr;
                }
                curr = curr->next;
            }
        }
        if(prev != nullptr)
            prev->next = nullptr;
        return newHead;
    }
};