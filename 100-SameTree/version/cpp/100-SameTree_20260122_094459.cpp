// Last updated: 1/22/2026, 9:44:59 AM
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
15        if(p == nullptr && q == nullptr){
16            return true;
17        } else if(p == nullptr || q == nullptr){
18            return false;
19        } else if(p->val != q->val){
20            return false;
21        } else {
22            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
23        }
24    }
25};