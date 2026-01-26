// Last updated: 1/26/2026, 8:04:46 PM
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
14    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
15        unordered_map<string, vector<TreeNode*>> mp;
16        string s;
17        traversal(root, s, mp);
18        vector<TreeNode*> duplicates;
19        for(auto it : mp){
20            if(it.second.size() > 1){
21                duplicates.push_back(it.second[0]);
22                continue;
23            }
24        }
25        return duplicates;
26    }
27
28    string traversal(TreeNode* root, string s, unordered_map<string, vector<TreeNode*>> &mp){
29        if(root == nullptr){
30            s += "(#)";
31            return s;
32        }
33        s += "(" + to_string(root->val) + ")" + traversal(root->left, s, mp) + traversal(root->right, s, mp);;
34        mp[s].push_back(root);
35        return s;
36    }
37};