// Last updated: 6/20/2026, 12:55:17 PM
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
13private:
14    bool subTreeDetected = false;
15public:
16    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
17        traverseAndMatch(root, subRoot);
18        return subTreeDetected;
19    }
20
21    void traverseAndMatch(TreeNode* root, TreeNode* subRoot){
22        bool match = isSameTree(root, subRoot);
23        if(match){
24            subTreeDetected = true;
25            return;
26        }
27        if(!root)
28            return;
29        traverseAndMatch(root->left, subRoot);
30        traverseAndMatch(root->right, subRoot);
31    }
32
33    bool isSameTree(TreeNode* p, TreeNode* q) {
34        if(p == nullptr && q == nullptr)
35            return true;
36        if(p == nullptr || q == nullptr || p->val != q->val)
37            return false;
38        int leftSubtree = isSameTree(p->left, q->left);
39        if(leftSubtree == false)
40            return false;
41        int rightSubtree = isSameTree(p->right, q->right);
42        return leftSubtree && rightSubtree;
43    }
44};