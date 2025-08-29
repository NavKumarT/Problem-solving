// Last updated: 8/29/2025, 9:52:19 PM
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
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        int temp =  preorder(root, 0, sum);
        return sum;
    }

    int preorder(TreeNode* root, int s, int &c){
        if(root == NULL)
            return s;
        if(root->left == NULL && root->right == NULL){
            c += s * 10 + root->val;
            return 0;
        }
        int sum = s * 10 + root->val;
        int left = preorder(root->left, sum, c);
        int right = preorder(root->right, sum, c);
        return left + right;
    }
};