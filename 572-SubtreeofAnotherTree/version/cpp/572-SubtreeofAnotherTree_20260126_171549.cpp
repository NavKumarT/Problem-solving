// Last updated: 1/26/2026, 5:15:49 PM
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
14    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
15        if(root == nullptr && subRoot == nullptr)
16            return true;
17        else if(root == nullptr || subRoot == nullptr)
18            return false;
19        bool check = utils(root, subRoot);
20        return check || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
21    }
22
23    // check sif the trees beginnning at these are the same 
24    bool utils(TreeNode* root, TreeNode* subRoot){
25        if(root == nullptr && subRoot == nullptr)   
26            return true;
27        else if(root == nullptr || subRoot == nullptr || root->val != subRoot->val)  
28            return false;
29        return utils(root->left, subRoot->left) && utils(root->right, subRoot->right);
30    }
31};