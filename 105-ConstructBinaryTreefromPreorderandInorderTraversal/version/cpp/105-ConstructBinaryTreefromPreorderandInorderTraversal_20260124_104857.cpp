// Last updated: 1/24/2026, 10:48:57 AM
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
14    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
15        int start = 0, end = preorder.size()-1, i = 0;
16        TreeNode* root = utils(preorder, inorder, i, start, end);
17        return root;
18    }
19
20    TreeNode* utils(vector<int> &preorder, vector<int> &inorder, int &i, int start, int end){
21        // get the index of the element in the inorder array 
22        if(start > end || i >= preorder.size())
23            return nullptr;
24        int inorderIdx = bSearch(inorder, start, end, preorder[i]);
25        TreeNode* node = new TreeNode(preorder[i]);
26        i++;
27        node->left = utils(preorder, inorder, i, start, inorderIdx-1);
28        node->right = utils(preorder, inorder, i, inorderIdx+1, end);
29        return node;
30    }
31
32    int bSearch(vector<int> &inorder, int start, int end, int element){
33        for(int i =start; i <= end; i++){
34            if(inorder[i] == element)
35                return i;
36        }
37        return -1;
38    }
39};