// Last updated: 11/04/2025, 15:15:27
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
    bool evaluateTree(TreeNode* root) {
        if(root == nullptr)
            return true;
        if(root->left == nullptr && root->right == nullptr)
            return root->val == 0 ? false : true;
        bool left = evaluateTree(root->left);
        if(left == false && root->val == 3) return false;
        bool right = evaluateTree(root->right);
        if(root->val == 2) return left || right;
        else return left && right;
    }
};