// Last updated: 4/26/2026, 11:52:41 AM
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
13    private:
14        vector<int> path;
15public:
16    vector<int> postorderTraversal(TreeNode* root) {
17        traversal(root);
18        return path;
19    }
20
21    void traversal(TreeNode* root){
22        if(root == nullptr)
23            return;
24        traversal(root->left);
25        traversal(root->right);
26        path.push_back(root->val);
27    }
28};