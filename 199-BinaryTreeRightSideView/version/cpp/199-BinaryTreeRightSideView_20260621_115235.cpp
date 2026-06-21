// Last updated: 6/21/2026, 11:52:35 AM
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
15        queue<TreeNode*> q;
16        q.push(root);
17        vector<int> rightViewList;
18        if(root == nullptr)
19            return rightViewList;
20        while(!q.empty()){
21            int size = q.size();
22            for(int i = 0; i < size; i++){
23                TreeNode* node = q.front();
24                q.pop();
25                if(i == size-1){
26                    rightViewList.push_back(node->val);
27                }
28                if(node->left)
29                    q.push(node->left);
30                if(node->right)
31                    q.push(node->right);
32            }
33        }
34        return rightViewList;
35    }
36};