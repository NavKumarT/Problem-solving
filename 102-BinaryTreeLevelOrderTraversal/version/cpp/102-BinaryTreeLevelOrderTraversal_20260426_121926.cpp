// Last updated: 4/26/2026, 12:19:26 PM
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
14    vector<vector<int>> levelOrder(TreeNode* root) {
15        vector<vector<int>> traversalList;
16        if(root == nullptr)
17            return traversalList;
18        queue<TreeNode*> q;
19        q.push(root);
20        while(!q.empty()){
21            int size = q.size();
22            vector<int> temp;
23            for(int i = 0; i < size; i++){
24                TreeNode* node = q.front();
25                q.pop();
26            temp.push_back(node->val);
27            if(node->left) 
28                q.push(node->left);
29            if(node->right)
30                q.push(node->right);
31            }
32            traversalList.push_back(temp);
33        }
34        return traversalList;
35    }
36};