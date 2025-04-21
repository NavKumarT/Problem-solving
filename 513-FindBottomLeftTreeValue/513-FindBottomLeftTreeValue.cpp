// Last updated: 21/04/2025, 16:05:11
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
    int findBottomLeftValue(TreeNode* root) {
        int maxLevel = INT_MIN, level = 0, ans = 0;
        traversal(root, level, maxLevel, ans);
        return ans;
    }

    void traversal(TreeNode* root, int level, int &maxLevel, int &ans){
        if(root == nullptr)
            return;
        if(level > maxLevel){
            maxLevel = level;
            ans = root->val;
        }
        traversal(root->left, level+1, maxLevel, ans);
        traversal(root->right, level+1, maxLevel, ans);
    }
};