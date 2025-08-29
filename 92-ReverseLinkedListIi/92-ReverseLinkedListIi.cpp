// Last updated: 8/29/2025, 9:52:39 PM
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
  ListNode* reverseBetween(ListNode* head, int left, int right) {
    if(left == right)
        return head;
    ListNode *rtailnext, *rheadprev, *prev = NULL, *curr = head, *rhead = head, *rtail;
    int count = 1;
    while(count <= right){
        if(count <= left){
            prev = rhead;
            rhead = curr;
        } 
        rtail = curr;
        curr = curr->next;
        count++;
    }
    rtailnext = rtail->next;
    rtail->next = NULL;
    rheadprev = prev;
    if(left != 1)
    rheadprev->next = NULL;
    if(left == 1)
        rhead = head;
    pair<ListNode*, ListNode*> p = reverseLL(rhead);
    ListNode *reversedhead = p.first;
    ListNode *reversedtail = p.second;
    // cout << rhead->val << endl;
    // cout << reversedhead->val << " " << reversedtail->val << endl;
    if(left != 1)
        rheadprev->next = reversedhead;
    reversedtail->next = rtailnext;
    if(left == 1)
        return reversedhead;
    return head;
}

pair<ListNode*, ListNode*> reverseLL(ListNode* head){
    ListNode* curr = head;
    ListNode* prev = NULL;
    ListNode* reversetail;
    while(curr != NULL){
        ListNode* next = curr->next;
        if(prev == NULL)
            reversetail = curr;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    pair<ListNode* , ListNode*> p;
    p.first = prev;
    p.second = reversetail;
    return p;
}
};