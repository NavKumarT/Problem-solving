// Last updated: 6/20/2026, 11:43:10 AM
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
12
13class Solution {
14public:
15    vector<int> inorderTraversal(TreeNode* root) {
16        vector<int> traversalList;
17        traversalUtils(root, traversalList);
18        return traversalList;
19    }
20
21    void traversalUtils(TreeNode* root, vector<int> &traversalList){
22        if(root == nullptr){
23            return;
24        }
25        traversalUtils(root->left, traversalList);
26        traversalList.push_back(root->val);
27        traversalUtils(root->right, traversalList);
28    }
29};