// Last updated: 10/04/2025, 18:34:37
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
    bool isBalanced(TreeNode* root) {
        // get the depth of left and right subtrees
        // if they differ by more than 1, then return false
        // else recursively repeat for left and right subtrees
        int count = 0;
        bool ans = true;
        int temp = traversal(count, root, ans);
        return ans;
    }


    int traversal(int count, TreeNode* root, bool &ans){
        if(root == nullptr)
            return count;
        int left = traversal(count+1, root->left, ans);
        int right = traversal(count+1, root->right, ans);
        if(abs(left-right) > 1)
            ans = false;
        return max(left, right);
    }
};