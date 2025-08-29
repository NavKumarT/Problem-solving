// Last updated: 8/29/2025, 9:51:42 PM
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
   ListNode* sortList(ListNode* head) {
    // find the middle of the list 
    if(head == NULL || head->next == NULL)
        return head;
    ListNode *fast = head, *slow  = head, *prev = NULL;
    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }
    prev->next = NULL;
    ListNode *left = sortList(head);
    ListNode *right = sortList(slow);
    return mergeSorted(left, right);
}

ListNode* findMiddle(ListNode* head){
    ListNode *fast = head, *slow  = head;
    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
ListNode *mergeSorted(ListNode* left, ListNode* right){
    ListNode *dummy = new ListNode(0);
    ListNode *mergedhead = dummy;
    while(left != NULL && right != NULL){
        if(left->val <= right->val){
            mergedhead->next = left;
            left = left->next;
            mergedhead = mergedhead->next;
        } else {
             mergedhead->next = right;
            right = right->next;
            mergedhead = mergedhead->next;
        }
    }
    if(left != NULL)
        mergedhead->next = left;
    if(right != NULL)
        mergedhead->next = right;
    return dummy->next;
}
};