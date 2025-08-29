// Last updated: 8/29/2025, 9:47:36 PM
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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> s;
        for(int num : nums)
            s.insert(num);
        
        ListNode* curr = head;
        ListNode *prev = nullptr, *next;
        while(s.find(head->val) != s.end()){
            next = head->next;
            head->next = nullptr;
            head = next;
        }

        prev = head; curr = head->next;
        while(curr != nullptr){
            if(s.find(curr->val) != s.end()){
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }

        return head;
    }
};