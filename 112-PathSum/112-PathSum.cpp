// Last updated: 11/04/2025, 12:01:54
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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr)
            return false;
        return traversal(root, 0, targetSum);
    }

    bool traversal(TreeNode* root, int curr, int target){
        if(root == nullptr)
            return false;

        // BASE CASE : If we reach the root, check if the path sum is equal to the target
        if(root->left == nullptr && root->right == nullptr)
            return curr + root->val == target;

        return traversal(root->left, curr + root->val, target) || traversal(root->right, curr + root->val, target);
    }
};