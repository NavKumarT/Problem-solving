// Last updated: 8/29/2025, 9:50:06 PM
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
    int minDiffInBST(TreeNode* root) {
        int largestSoFar = INT_MIN;
        int ans = INT_MAX;
        traversal(root, largestSoFar, ans);
        return ans;
    }

    void traversal(TreeNode* root, int &largestSoFar, int &ans){
        if(root == nullptr) return;
        traversal(root->left, largestSoFar, ans);
        if(largestSoFar == INT_MIN){
            largestSoFar = root->val;
        }
        else {
            ans = min(ans, root->val - largestSoFar);
            largestSoFar = root->val;
        }
        traversal(root->right, largestSoFar, ans);
    }
};