// Last updated: 6/20/2026, 12:21:29 PM
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
14    bool isBalancedTree = true;
15public:
16    bool isBalanced(TreeNode* root) {
17        int temp = utils(root); // utils function that measures the depth of a tree 
18        return isBalancedTree;
19    }
20
21    // find the depth of every left subtree and right subtree
22    // set isBalancedTree based on the difference 
23    int utils(TreeNode* root){
24        if(root == nullptr)
25            return 0;
26        int left = utils(root->left);
27        int right = utils(root->right);
28        if(abs(left-right) > 1){
29            isBalancedTree = false;
30            return 0;
31        }
32        return 1 + max(left, right);
33    }
34};