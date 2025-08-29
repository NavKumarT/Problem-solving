// Last updated: 8/29/2025, 9:52:57 PM
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k == 0)
            return head;
        // get the size fo the linkedlist
        int size = 0;
        ListNode *curr = head;
        while(curr != NULL){
            size++;
            curr = curr->next;
        }
        // get the kth node from the end of the linked list and the preceding node
        curr = head;
        k = k % size;
        if(k == 0)
            return head;
        ListNode *prev = NULL, *headStart = head;
        for(int i = 0; i < k; i++)
            headStart = headStart->next;
        
        while(headStart != NULL){
            prev = curr;
            curr = curr->next;
            headStart = headStart->next;
        }
        prev->next = NULL;
        ListNode* newhead = curr;
        while(curr->next != NULL)
            curr = curr->next;
        curr->next = head;
        return newhead;
    }
};