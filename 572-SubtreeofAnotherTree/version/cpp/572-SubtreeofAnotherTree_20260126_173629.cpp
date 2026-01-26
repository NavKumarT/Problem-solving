// Last updated: 1/26/2026, 5:36:29 PM
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
15        string s1, s2;
16        serialize(root, s1);
17        serialize(subRoot, s2);
18        return s1.find(s2) != string::npos;
19    }
20
21    void serialize(TreeNode* root, string &s){
22        if(root == nullptr){
23            s += "(#)";
24            return;
25        }
26        s += "(" + to_string(root->val) + ")";
27        serialize(root->left, s);
28        serialize(root->right, s);
29    }
30};