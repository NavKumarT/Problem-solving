// Last updated: 6/20/2026, 11:44:24 AM
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
14    vector<int> preorderTraversal(TreeNode* root) {
15        vector<int> traversalList;
16        traversalUtils(root, traversalList);
17        return traversalList;
18    }
19
20    void traversalUtils(TreeNode* root, vector<int> &traversalList){
21        if(root == nullptr){
22            return;
23        }
24        traversalList.push_back(root->val);
25        traversalUtils(root->left, traversalList);
26        traversalUtils(root->right, traversalList);
27    }
28};