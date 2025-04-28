// Last updated: 28/04/2025, 19:29:36
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
    bool isValidBST(TreeNode* root) {
        return func(root, LONG_MIN, LONG_MAX);
    }

    bool func(TreeNode* root, long long low, long long high){
        if(root == nullptr)
            return true;
        if(root->val > low && root->val < high){
            return func(root->left, low, root->val) &&  func(root->right, root->val, high);
        } else 
        return false;
    }
};