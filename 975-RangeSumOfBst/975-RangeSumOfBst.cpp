// Last updated: 8/29/2025, 9:49:46 PM
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
    int rangeSumBST(TreeNode* root, int low, int high) {
        int ans = 0; // The result to be returned 
        rangeSumTraversalForBST(root, low, high, ans);
        return ans;
    }

    // Time Complexity : O(n) Space Complexity: O(n)
    void rangeSumTraversalForBST(TreeNode* root, int low, int high, int &ans){
        if(root == nullptr)
            return;
        
        if(root->val >= low && root->val <= high){
            ans += root->val;
            rangeSumTraversalForBST(root->left, low, high, ans);
            rangeSumTraversalForBST(root->right, low, high, ans);
        } else if(root->val > high){
            rangeSumTraversalForBST(root->left, low, high, ans);
        } else {
            rangeSumTraversalForBST(root->right, low, high, ans);
        }
    }
};