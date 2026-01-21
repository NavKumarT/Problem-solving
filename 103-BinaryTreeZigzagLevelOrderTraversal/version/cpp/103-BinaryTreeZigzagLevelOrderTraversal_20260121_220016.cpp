// Last updated: 1/21/2026, 10:00:16 PM
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
14    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
15        vector<vector<int>> ans;
16        queue<TreeNode*> q;
17        if(root == nullptr)
18            return ans;
19        q.push(root);
20        int reverseFlag = false;
21        while(q.empty() == false){
22            int size = q.size();
23            vector<int> temp;
24            while(size--){
25                TreeNode* node = q.front();
26                q.pop();
27                if(node->left)
28                    q.push(node->left);
29                if(node->right)
30                    q.push(node->right);
31                temp.push_back(node->val);
32            }
33            if(reverseFlag)
34                reverse(temp.begin(), temp.end());
35            reverseFlag = !reverseFlag;
36            ans.push_back(temp);
37        }
38        return ans;
39    }
40};