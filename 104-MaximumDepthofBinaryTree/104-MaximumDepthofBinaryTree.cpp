// Last updated: 10/04/2025, 16:35:50
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
    int maxDepth(TreeNode* root) {
        int count = 1;
        if(root == nullptr)
            return 0;
        int ans = 1;
        traversal(ans, count, root);
        return ans;
    }

    void traversal(int &ans, int count, TreeNode* root){
        if(root == nullptr)
            return;
        ans = max(ans, count);
        traversal(ans, count+1, root->left);
        traversal(ans, count+1, root->right);
    }
};