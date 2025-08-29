// Last updated: 8/29/2025, 9:52:34 PM
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
    bool isSymmetric(TreeNode* root) {
        return compare(root->left, root->right);
    }

    bool compare(TreeNode* left, TreeNode* right){
        if((left == nullptr && right != nullptr) || (left != nullptr && right == nullptr))
            return false;
        else if(left == nullptr && right == nullptr)
            return true;
        
        if(left->val == right->val && compare(left->right, right->left) && compare(left->left, right->right))
            return true;
        else 
            return false;
    }
};