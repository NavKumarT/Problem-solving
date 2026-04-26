// Last updated: 4/26/2026, 11:58:48 AM
1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
8 * };
9 */
10
11class Solution {
12public:
13    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
14        if(root == nullptr)
15            return root;
16        
17        if((root->val > min(p->val, q->val) && root->val <  max(p->val, q->val)) || root->val == p->val || root->val == q->val)
18            return root;
19        else if(root->val > min(p->val, q->val))
20            return lowestCommonAncestor(root->left, p, q);
21        else 
22            return lowestCommonAncestor(root->right, p, q);
23    }
24};