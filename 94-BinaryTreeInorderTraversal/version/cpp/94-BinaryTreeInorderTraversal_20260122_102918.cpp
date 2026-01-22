// Last updated: 1/22/2026, 10:29:18 AM
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
14    vector<int> inorderTraversal(TreeNode* root) {
15        vector<int> traversal;
16        utils(root, traversal);
17
18        return traversal;
19    }
20
21    void utils(TreeNode* root, vector<int> &traversal){
22        if(root == nullptr)
23            return;
24        utils(root->left, traversal);
25        traversal.push_back(root->val);
26        utils(root->right, traversal);
27    }
28};