// Last updated: 8/29/2025, 9:51:16 PM
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
    int kthSmallest(TreeNode* root, int k) {
        int count = 0, ans = -1;
        traversal(root, count, k, ans);
        return ans;
    }

    void traversal(TreeNode* root, int &count, int k, int &ans){
        if(root == nullptr){
            return;
        }
        traversal(root->left, count, k, ans);
        count++;
        if(count == k){
            ans = root->val;
            return;
        } 
        traversal(root->right, count, k, ans);
    }
};