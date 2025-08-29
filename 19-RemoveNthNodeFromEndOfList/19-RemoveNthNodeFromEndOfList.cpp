// Last updated: 8/29/2025, 9:53:20 PM
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *second = head, *first = head, *prev = nullptr;
        while(n > 0){
            n--;
            second = second->next;
        }
        while(second != nullptr){
            second = second->next;
            prev = first;
            first = first->next;
        }
        if(prev == nullptr)
            return head->next;
        ListNode *nodeToBeDeleted = prev->next;
        prev->next = prev->next->next;
        delete nodeToBeDeleted;
        return head;
    }
};