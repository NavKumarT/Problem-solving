// Last updated: 6/21/2026, 11:26:53 AM
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
15        string rootSerializedString = "", subRootSerializedString = "";
16        serializeTree(root, rootSerializedString);
17        serializeTree(subRoot, subRootSerializedString);
18        return rootSerializedString.contains(subRootSerializedString);
19    }
20
21    void serializeTree(TreeNode* root, string &str){
22        if(root == nullptr){
23            str += "#";
24            return;
25        }
26        str += "\"" + to_string(root->val) + "\""  + "#";
27        serializeTree(root->left, str);
28        serializeTree(root->right, str); 
29    }
30};