// Last updated: 4/26/2026, 11:51:39 AM
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
15        vector<int> traversalList;
16        traversal(traversalList, root);
17        return traversalList;
18    }
19
20    void traversal(vector<int> &traversalList, TreeNode* node){
21        if(node == nullptr)
22            return;
23        traversal(traversalList, node->left);
24        traversalList.push_back(node->val);
25        traversal(traversalList, node->right);
26    }
27};