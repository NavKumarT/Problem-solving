// Last updated: 1/22/2026, 12:03:11 AM
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
14    int maxLevelSum(TreeNode* root) {
15        int ans = -1;
16        int sum = INT_MIN;
17        if(root == nullptr)
18            return ans;
19        queue<TreeNode*> q;
20        q.push(root);
21        int level = 1;
22        while(q.empty() == false){
23            int size = q.size();
24            int curr = 0;
25            while(size--){
26                TreeNode* node = q.front();
27                q.pop();
28                if(node->left)
29                    q.push(node->left);
30                if(node->right)
31                    q.push(node->right);
32                curr += node->val;
33            }
34            if(curr > sum){
35                sum = curr;
36                ans = level;
37            }
38            level++;
39        }
40        return ans;
41    }
42};