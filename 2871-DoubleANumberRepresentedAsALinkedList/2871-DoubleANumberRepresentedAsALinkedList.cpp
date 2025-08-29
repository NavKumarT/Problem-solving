// Last updated: 8/29/2025, 9:47:57 PM
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
    ListNode* doubleIt(ListNode* head) {
        // same as the add 2 nums question, just that the nums are same now 
        // reverse karo first, answer nikalo and then phir reverse karo 
        head = reverse(head);
        int carry = 0;
        ListNode *curr = head, *newHead = nullptr, *prev = nullptr;
        while(curr != nullptr){
            int sum = curr->val * 2 + carry;
            carry = sum / 10;
            int val = sum % 10;
            ListNode *node = new ListNode(val);
            if(newHead == nullptr)
                newHead = node;
            else 
                prev->next = node;
            prev = node;
            curr = curr->next;
        }
        if(carry != 0){
            ListNode *node = new ListNode(carry);
            prev->next = node;
            prev = node;
        }
        newHead = reverse(newHead);
        return newHead;
    }

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

    // sirf 8% ?!!!! optmze !!!

};