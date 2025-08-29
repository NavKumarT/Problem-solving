// Last updated: 8/29/2025, 9:51:37 PM
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // find the length of both the LLs 
        // give the longer LL a headstart 
        // traverse both the LLs now and return if they intersect 
        long long unsigned int m = 0, n = 0;
        ListNode *temp1 = headA, *temp2 = headB;
        while(temp1 != NULL){
            m++;
            temp1 = temp1->next;
        }
        while(temp2 != NULL){
            n++;
            temp2 = temp2->next;
        }
        long long int count = m > n ? m-n : n-m;
        if(m > n){
            while(count > 0){
                count--;
                headA = headA->next;
            }
        } else {
            while(count > 0){
                count--;
                headB = headB->next;
            }
        }

        while(headA != NULL && headB != NULL){
            if(headA == headB)
                return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return nullptr;
    }
};