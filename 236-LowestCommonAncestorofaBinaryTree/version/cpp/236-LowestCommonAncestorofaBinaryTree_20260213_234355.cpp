// Last updated: 2/13/2026, 11:43:55 PM
1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
8 * };
9 */
10class Solution {
11public:
12    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
13        if(root == nullptr)
14            return nullptr;
15        if(root->val == p->val || root->val == q->val)
16            return root;
17            TreeNode *lca1 = lowestCommonAncestor(root->left, p, q);
18            TreeNode *lca2 = lowestCommonAncestor(root->right, p, q);
19        if(lca1 != nullptr && lca2 != nullptr)
20        return root;
21        else if(lca1 != nullptr)
22            return lca1;
23        else 
24        return lca2;
25    }
26};