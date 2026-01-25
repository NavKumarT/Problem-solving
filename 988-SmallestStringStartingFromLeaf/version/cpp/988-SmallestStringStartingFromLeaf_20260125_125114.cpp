// Last updated: 1/25/2026, 12:51:14 PM
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
14    string smallestFromLeaf(TreeNode* root) {
15        string path = "";
16        string curr = "";
17        traversal(root, path, curr);
18        return path;
19    }
20
21    void traversal(TreeNode* root, string &path, string curr){
22        if(root == nullptr)
23            return;
24        curr += root->val+'a';
25        if(root->left == nullptr && root->right == nullptr){
26            reverse(curr.begin(), curr.end());
27            if(path.length() == 0 ||  curr < path){
28                path = curr;
29            }
30            return;
31        }
32        traversal(root->left, path, curr);
33        traversal(root->right, path, curr);
34
35    }
36};