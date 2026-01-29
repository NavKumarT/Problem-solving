// Last updated: 1/29/2026, 8:08:06 PM
1class Solution {
2public:
3    vector<int> ans;
4    int maxCount = 0;
5    int currCount = 0;
6    int prev = INT_MIN;
7
8    vector<int> findMode(TreeNode* root) {
9        inorder(root);
10        return ans;
11    }
12
13    void inorder(TreeNode* node) {
14        if (!node) return;
15
16        inorder(node->left);
17
18        // process current node
19        if (node->val == prev) {
20            currCount++;
21        } else {
22            prev = node->val;
23            currCount = 1;
24        }
25
26        if (currCount > maxCount) {
27            maxCount = currCount;
28            ans.clear();
29            ans.push_back(node->val);
30        } else if (currCount == maxCount) {
31            ans.push_back(node->val);
32        }
33
34        inorder(node->right);
35    }
36};
37