// Last updated: 1/25/2026, 11:51:52 AM
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
14    vector<int> postorderTraversal(TreeNode* root) {
15        vector<int> path;
16        traversal(root, path);
17        return path;
18    }
19
20    void traversal(TreeNode* root, vector<int> &path){
21        if(root == nullptr)
22            return;
23        traversal(root->left, path);
24        traversal(root->right, path);
25        path.push_back(root->val);
26    }
27};