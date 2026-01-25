// Last updated: 1/25/2026, 11:33:35 AM
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
14    vector<string> binaryTreePaths(TreeNode* root) {
15        vector<string> paths;
16        string path;
17        traversal(root, paths, path);
18        return paths;
19    }
20
21    void traversal(TreeNode* root, vector<string> &paths, string path){
22        if(root == nullptr)
23            return;
24        if(path.length() != 0)
25            path += "->";
26        path += to_string(root->val);
27        if(root->left == nullptr && root->right == nullptr){
28            paths.push_back(path);
29            return;
30        }
31        traversal(root->left, paths, path);
32        traversal(root->right, paths, path);
33    }
34};