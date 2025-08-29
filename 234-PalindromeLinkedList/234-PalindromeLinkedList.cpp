// Last updated: 8/29/2025, 9:51:14 PM
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
ListNode* reverse(ListNode* head){
    ListNode *curr = head, *prev = nullptr, *next;
    while(curr != nullptr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
    bool isPalindrome(ListNode* head) {
        // get the length of the ll 
        int count=0;
        ListNode* curr = head;
        while(curr != nullptr){
            count++;
            curr = curr->next;
        }
        curr = head;
        count = count/2;
        while(count-1 > 0){
            curr = curr->next;
            count--;
        }
        ListNode* secondHead = curr->next;
        curr->next = nullptr;
        secondHead = reverse(secondHead);
        while(secondHead != nullptr && head != nullptr){
            if(secondHead->val != head->val)
                return false;
                secondHead = secondHead->next;
                head = head->next;
        }
        return true;
    }

};