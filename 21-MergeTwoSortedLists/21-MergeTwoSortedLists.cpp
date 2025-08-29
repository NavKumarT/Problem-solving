// Last updated: 8/29/2025, 9:53:16 PM
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummyHead = new ListNode(-1);
        ListNode* curr = dummyHead;
        while(list1 != nullptr && list2 != nullptr){
            if(list1->val <= list2->val){
                curr->next = list1;
                curr = curr->next;
                list1 = list1->next;
            } else {
                curr->next = list2;
                curr = curr->next;
                list2 = list2->next;
            }
        }
        if(list1 != nullptr){
            curr->next = list1;
        }
        if(list2 != nullptr){
            curr->next = list2;
        }
        return dummyHead->next;
    }
};