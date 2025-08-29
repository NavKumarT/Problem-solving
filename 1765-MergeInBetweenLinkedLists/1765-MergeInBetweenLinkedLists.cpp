// Last updated: 8/29/2025, 9:48:56 PM
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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *prevOfRemoved = nullptr, *nextOfPtr = nullptr;
        ListNode *curr = list1, *prev = nullptr, *next = nullptr;
        int count = 0;
        while(curr != nullptr){
            if(count == a){
                prevOfRemoved = prev;
            } 
            if(count == b){
                nextOfPtr = curr->next;
                break;
            }
            prev = curr;
            curr = curr->next;
            count++;
        }

        prevOfRemoved->next = list2;
        prev = nullptr; curr = list2;
        while(curr != nullptr){
            prev = curr;
            curr = curr->next;
        }
        prev->next = nextOfPtr;
        return list1;
    }
};