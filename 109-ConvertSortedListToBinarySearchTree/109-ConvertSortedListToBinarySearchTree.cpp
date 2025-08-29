// Last updated: 8/29/2025, 9:52:27 PM
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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        // BASE CASE FOR RECURSION
        if(head == nullptr)
            return nullptr;
        
        // ANOTHER BASE CASE FOR RECURSION
        if(head->next == nullptr){
            TreeNode* root = new TreeNode(head->val);
            root->left = nullptr;
            root->right = nullptr;
            return root;
        }
        // MAKE THE MIDDLE THE ROOT, LEFT AND RIGHT WILL BE RECURSIVELY CALLED 
        ListNode *fast = head, *slow = head, *prev = nullptr;
        while(fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        prev->next = nullptr;  // DISCONNECT THE FIRST HALF FROM THE SECOND HALF 
        
        TreeNode* root = new TreeNode(slow->val);
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(slow->next);
        return root;
    }
};