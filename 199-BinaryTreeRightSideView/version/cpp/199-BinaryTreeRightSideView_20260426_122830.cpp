// Last updated: 4/26/2026, 12:28:30 PM
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
15        vector<int> traversalList; 
16        if(root == nullptr)
17        return traversalList;
18        queue<TreeNode*> q;
19        q.push(root);
20        while(!q.empty()){
21            int size = q.size();
22            for(int i = 0 ; i < size; i++){
23                TreeNode* node = q.front();
24            q.pop();
25            if(i == size-1)
26                traversalList.push_back(node->val);
27            if(node->left)
28                q.push(node->left);
29            if(node->right)
30                q.push(node->right);
31            }
32        }
33        return traversalList;
34    }
35};