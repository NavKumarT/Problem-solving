// Last updated: 8/29/2025, 9:50:09 PM
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == nullptr)
            return new TreeNode(val);
        func(root, val);
        return root;
    }
    void func(TreeNode* root, int val) {
        if(val > root->val){
            if(root->right == nullptr){
                root->right = new TreeNode(val);
                return;
            } else {
                func(root->right, val);
            }
        } else {
            if(root->left == nullptr){
                root->left = new TreeNode(val);
                return;
            } else {
                func(root->left, val);
            }
        }
    }
};