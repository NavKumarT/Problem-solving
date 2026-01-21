// Last updated: 1/21/2026, 9:53:52 PM
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
15        vector<vector<int>> ans;
16        queue<TreeNode*> q;
17        if(root == nullptr)
18            return ans;
19        q.push(root);
20        while(q.empty() == false){
21            int size = q.size();
22            vector<int> level;
23            while(size--){
24                TreeNode* node = q.front();
25                q.pop();
26                if(node->left){
27                    q.push(node->left);
28                }
29                if(node->right){
30                    q.push(node->right);
31                }
32                level.push_back(node->val);
33            }
34            ans.push_back(level);
35        }
36        return ans;
37    }
38};