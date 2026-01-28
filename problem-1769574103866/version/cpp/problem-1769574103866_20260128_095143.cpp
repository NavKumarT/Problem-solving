// Last updated: 1/28/2026, 9:51:43 AM
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
14    int goodNodes(TreeNode* root) {
15        int maximum = INT_MIN;
16        int count = 0;
17        dfs(root, count, maximum);
18        return count;
19    }
20
21    void dfs(TreeNode* root, int &count, int maximum){
22        if(root == nullptr)
23            return;
24        if(root->val >= maximum){
25            maximum = root->val;
26            count++;
27        }
28        dfs(root->left, count, maximum);
29        dfs(root->right, count, maximum);
30    }
31};