// Last updated: 1/25/2026, 1:12:20 PM
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
14    int diameterOfBinaryTree(TreeNode* root) {
15        int ans = INT_MIN;
16        utils(root, ans);
17        return ans;
18    }
19
20    int utils(TreeNode* root, int &ans){
21        if(root == nullptr)
22            return 0;
23        int left = utils(root->left, ans);
24        int right = utils(root->right, ans);
25        ans = max(ans, left+right);
26        return max(left, right)+1;
27    }
28};