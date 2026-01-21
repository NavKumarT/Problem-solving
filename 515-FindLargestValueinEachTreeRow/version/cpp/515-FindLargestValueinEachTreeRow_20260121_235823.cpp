// Last updated: 1/21/2026, 11:58:23 PM
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
14    vector<int> largestValues(TreeNode* root) {
15        vector<int> res;
16        queue<TreeNode*> q;
17        if(root == nullptr)
18            return res;
19        q.push(root);
20        while(q.empty() == false){
21            int size = q.size();
22            int maximum = INT_MIN;
23            while(size){
24                TreeNode* node = q.front();
25                q.pop();
26                int val = node->val;
27                maximum = max(maximum,val);
28                if(node->left)
29                    q.push(node->left);
30                if(node->right)
31                    q.push(node->right);
32                size--;
33            }
34            res.push_back(maximum);
35        }
36        return res;
37
38    }
39};