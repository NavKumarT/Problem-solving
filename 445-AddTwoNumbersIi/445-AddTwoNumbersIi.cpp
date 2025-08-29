// Last updated: 8/29/2025, 9:50:48 PM
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);
        return reverse(addTwoNumbersUtil(l1, l2));
    }

     ListNode* addTwoNumbersUtil(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode *head = new ListNode(-1), *curr = head;
        while(l1 != nullptr ||  l2 != nullptr){
            ListNode* temp = new ListNode();
            int firstVal = l1 != nullptr ? l1->val : 0;
            int secondVal = l2 != nullptr ? l2->val : 0;
            int sum = firstVal + secondVal + carry;
            carry = sum / 10;
            temp->val = sum % 10;
            curr->next = temp;
            curr = curr->next;
            if(l1 != nullptr)
                l1 = l1->next;
            if(l2 != nullptr)
                l2 = l2->next;
        }
        if(carry != 0)
            curr->next = new ListNode(carry);
        return head->next;
    }

    ListNode* reverse(ListNode* head){
        ListNode *prev = nullptr, *next = nullptr, *curr = head;
        while(curr != nullptr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};