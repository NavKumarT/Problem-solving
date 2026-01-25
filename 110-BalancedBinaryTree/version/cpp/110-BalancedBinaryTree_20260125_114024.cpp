// Last updated: 1/25/2026, 11:40:24 AM
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
14    bool isBalanced(TreeNode* root) {
15        bool balanced = true;
16        int height = utils(root, balanced);
17        return balanced;
18    }
19
20    int utils(TreeNode* root, bool &balanced){
21        if(root == nullptr)
22            return 0;
23        if(root->left == nullptr && root->right == nullptr)
24            return 1;
25        int left = utils(root->left, balanced);
26        int right = utils(root->right, balanced);
27        if(abs(left-right) > 1){
28            balanced = false;
29        }
30        return max(left, right)+1;
31    }
32};