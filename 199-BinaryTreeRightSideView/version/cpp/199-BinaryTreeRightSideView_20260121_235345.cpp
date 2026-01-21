// Last updated: 1/21/2026, 11:53:45 PM
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
14    vector<int> rightSideView(TreeNode* root) {
15        vector<int> res;
16        queue<TreeNode*> q;
17        if(root == nullptr)
18            return res;
19        q.push(root);
20        while(q.empty() == false){
21            int size = q.size();
22            while(size){
23                TreeNode* node = q.front();
24                q.pop();
25                if(node->left)
26                    q.push(node->left);
27                if(node->right)
28                    q.push(node->right);
29                if(size == 1)
30                    res.push_back(node->val);
31                size--;
32            }
33        }
34        return res;
35    }
36};