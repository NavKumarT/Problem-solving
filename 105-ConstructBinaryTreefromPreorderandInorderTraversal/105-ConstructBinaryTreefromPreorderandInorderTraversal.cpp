// Last updated: 29/04/2025, 12:14:53
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++)
            mp[inorder[i]] = i;
        int index = 0;
        return func(preorder, inorder, 0, n-1, index, mp);
    }

    TreeNode* func(vector<int> &preorder, vector<int> &inorder, int low, int high, int &i, unordered_map<int, int> &mp){
        if(low > high)
            return nullptr;
        TreeNode* node = new TreeNode(preorder[i]);
        int curr = mp[preorder[i]];
        i++;
        node->left = func(preorder, inorder, low, curr-1, i, mp);
        node->right = func(preorder, inorder, curr+1, high, i, mp);
        return node;
    }
};