// Last updated: 6/20/2026, 12:49:33 PM
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
14    bool isSameTree(TreeNode* p, TreeNode* q) {
15        if(p == nullptr && q == nullptr)
16            return true;
17        if(p == nullptr || q == nullptr || p->val != q->val)
18            return false;
19        int leftSubtree = isSameTree(p->left, q->left);
20        if(leftSubtree == false)
21            return false;
22        int rightSubtree = isSameTree(p->right, q->right);
23        return leftSubtree && rightSubtree;
24    }
25};