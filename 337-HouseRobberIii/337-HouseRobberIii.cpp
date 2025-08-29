// Last updated: 8/29/2025, 9:51:02 PM
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
    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int> memo;
        memo[nullptr] = 0;
        return utils(root, memo);
    }

    int utils(TreeNode* root, unordered_map<TreeNode*, int> &memo){
        if(memo.find(root) != memo.end())
            return memo[root];

        int res = root->val;
        if(root->left)
            res = res + utils(root->left->left, memo) + utils(root->left->right, memo);
        if(root->right)
            res = res + utils(root->right->left, memo) + utils(root->right->right, memo);
        int ans =  max(res, utils(root->left, memo) + utils(root->right, memo));
        memo[root] = ans;
        return ans;
    }
};