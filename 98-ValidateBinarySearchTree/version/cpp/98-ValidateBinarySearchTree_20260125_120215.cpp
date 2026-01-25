// Last updated: 1/25/2026, 12:02:15 PM
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
14    bool isValidBST(TreeNode* root) {
15        long long start = LLONG_MIN, end = LLONG_MAX;
16        return utils(root, start, end);
17    }
18
19    bool utils(TreeNode* root, long long start, long long end){
20        if(root == nullptr)
21            return true;
22        if(root->val <= start || root->val >= end)
23            return false;
24        bool left = utils(root->left, start, root->val);
25        if(!left)
26            return false;
27        bool right = utils(root->right, root->val, end);
28        if(!right)
29            return false;
30        return true;
31    }
32};