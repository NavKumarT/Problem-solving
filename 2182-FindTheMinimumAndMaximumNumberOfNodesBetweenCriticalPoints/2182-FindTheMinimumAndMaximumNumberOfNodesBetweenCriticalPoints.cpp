// Last updated: 8/29/2025, 9:48:35 PM
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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        // if i get the indices of minimas and maximas in an array while traversing the LL once, 
        // then the last index - first index of the array will be the maximum value 
        // also i can traverse the array and find the minimum difference between consecutive elements
        // base case: if the length of that array is less than 2, then [-1, -1]. 

        ListNode *curr = head->next, *prev = head, *next = nullptr;
        vector<int> indices;
        int count = 1;
        while(curr->next != nullptr){
            if((curr->val < prev->val) && (curr->val < curr->next->val))
                indices.push_back(count);
            else if((curr->val > prev->val) && (curr->val > curr->next->val))
                indices.push_back(count);
            count++;
            prev = curr;
            curr = curr->next;
        }
        if(indices.size() < 2)
            return {-1, -1};
        int maximum = indices.back() - indices[0];
        int minimum = INT_MAX;
        for(int i = 1; i < indices.size(); i++)
            minimum = min(minimum, indices[i]-indices[i-1]);
        return {minimum, maximum};
    }
};