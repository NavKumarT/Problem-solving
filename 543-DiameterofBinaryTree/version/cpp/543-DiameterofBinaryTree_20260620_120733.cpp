// Last updated: 6/20/2026, 12:07:33 PM
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
13private:
14    int maxDepth;
15public:
16    int diameterOfBinaryTree(TreeNode* root) {
17        int temp = utils(root);
18        return maxDepth;
19    }
20
21    int utils(TreeNode* root){
22        if(root == nullptr)
23            return 0;
24        int left = utils(root->left);
25        int right = utils(root->right);
26        maxDepth = max(maxDepth, left+right);
27        return 1 + max(left, right);
28    }
29};