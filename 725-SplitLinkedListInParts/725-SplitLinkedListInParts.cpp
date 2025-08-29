// Last updated: 8/29/2025, 9:50:17 PM
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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans;   // final answer array 

        // STEP 1 : find the length of the Linked List
        // This helps us to know the minSize for the split
        int length = 0;
        ListNode* curr = head;
        while(curr != nullptr){
            curr = curr->next;
            length++;
        }

        // If the length of the linkedList is not completely divisible into k parts
        // we need to make sure to distribute the carry evenly. 
        // if length = 8 and k = 3, we need to (2 + 1) + (2 + 1) + 2. 
        // The first 2 splits will share the carry of 8 % 3 = 2.
        curr = head;
        int carry = length % k;
        int minSize = length / k;
        int numberOfSubLists = 0;
        while(curr != nullptr){
            ListNode *temp = curr, *prev = nullptr;
            int i = 0;
            // add the min number of nodes
            while(curr != nullptr && i < minSize){
                prev = curr;
                curr = curr->next;
                i++;
            }
            // If we have carry, add one to the current split
            if(carry > 0){
                prev = curr;
                curr = curr->next;
                carry--;
            }
            prev->next = nullptr;
            numberOfSubLists++;
            ans.push_back(temp);
        }
        while(numberOfSubLists < k){
            ans.push_back(nullptr);
            numberOfSubLists++;
        }
        return ans;
    }
};