// Last updated: 8/29/2025, 9:49:40 PM
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
    string smallestFromLeaf(TreeNode* root) {
        return traversal(root, "");
    }

    string traversal(TreeNode* root, string curr){
        if(root == NULL)
            return curr;
        string newCurr = char(root->val + 97) + curr;
        if(root->left == NULL)
            return traversal(root->right, newCurr); 
        else if(root->right == NULL)
            return traversal(root->left, newCurr); 
        string left = traversal(root->left, newCurr);
        string right = traversal(root->right, newCurr); 
        if(left < right )
            return left ;
        else    
            return right ;
    }
};