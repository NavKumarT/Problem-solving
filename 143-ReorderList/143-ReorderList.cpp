// Last updated: 8/29/2025, 9:51:44 PM
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
    void reorderList(ListNode* head) {
        ListNode *fast = head, *slow = head, *prev = head;
        while(fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        if(fast != nullptr){
            prev = slow;
            slow = slow->next;
        }
        prev->next = nullptr;
        slow = reverse(slow);
        merge(head, slow);
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

    void merge(ListNode* head1, ListNode* head2){
        ListNode *curr1 = head1, *curr2 = head2, *next1, *next2;
        ListNode *dummy = new ListNode(-1), *curr = dummy;
        while(curr1 != nullptr){
            dummy->next = curr1;
            next1 = curr1->next;
            next2 = curr2 != nullptr ? curr2->next : curr2;
            curr1->next = curr2;
            dummy = curr2;
            curr1 = next1;
            curr2 = next2;
        }
        
    }
};