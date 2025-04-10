// Last updated: 10/04/2025, 17:16:27
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
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        int count = 0;
        int temp = traversal(root, ans, count);
        return ans;
    }

    int traversal(TreeNode* root, int &ans, int count){
        if(root == nullptr)
            return count;
        int left = root->left != nullptr ? traversal(root->left, ans, count+1) : count;
        int right = root->right != nullptr ? traversal(root->right, ans, count+1) : count;
        ans = max(abs(left-count) + abs(right-count), ans);
        return max(left, right);
    }
};