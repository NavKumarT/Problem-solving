// Last updated: 1/25/2026, 12:20:08 PM
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
14    int kthSmallest(TreeNode* root, int k) {
15        int count = 0, kthSmallest = -1;
16        traversal(root, k, count, kthSmallest);
17        return kthSmallest;
18    }
19
20    void traversal(TreeNode* root, int k, int &count, int &kthSmallest){
21        if(kthSmallest != -1)
22            return;
23        if(root == nullptr)
24            return;
25        traversal(root->left, k, count, kthSmallest);
26        count++;
27        if(count == k){
28            kthSmallest = root->val;
29            return;
30        }
31        traversal(root->right, k, count, kthSmallest);
32    }
33};