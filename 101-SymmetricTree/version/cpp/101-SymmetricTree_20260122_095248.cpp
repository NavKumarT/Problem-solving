// Last updated: 1/22/2026, 9:52:48 AM
1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
8 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
9 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
10 * };
11 */
12class Solution {
13public:
14    bool isSymmetric(TreeNode* root) {
15        if(root == nullptr)
16            return true;
17        return utils(root->left, root->right);
18    }
19
20    bool utils(TreeNode* left, TreeNode* right){
21        if(left == nullptr && right == nullptr){
22            return true;
23        } else if(left == nullptr || right == nullptr){
24            return false;
25        } else if(left->val != right->val){
26            return false;
27        } else {
28            return utils(left->left, right->right) && utils(left->right, right->left);
29        }
30    }
31};