// Last updated: 8/29/2025, 9:49:08 PM
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
    int goodNodes(TreeNode* root) {
        int k = INT_MIN;
        int count = 0;
        func(root, k, count);
        return count;
    }

    void func(TreeNode* root, int k, int &count){
        if(root == nullptr)
            return;
        if(root->val >= k){
            count++;
            k = max(k, root->val);
        }
        func(root->left, k, count);
        func(root->right, k, count);
    }
};