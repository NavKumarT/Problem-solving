// Last updated: 8/29/2025, 9:52:30 PM
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
        int index = -1;
        return func(0, inorder.size(), index, preorder, inorder);
    }

    TreeNode* func(int start, int end, int &index, vector<int> &preorder, vector<int> &inorder){
        if(start > end || index+1 >= inorder.size())
            return nullptr;
        int x ;
        index++;
        TreeNode* n = new TreeNode(preorder[index]);
        for(int i = 0; i < inorder.size(); i++){
            if(inorder[i] == preorder[index]){
x = i;
            }
        }
        n->left = func(start, x-1, index, preorder, inorder);
        n->right = func(x+1, end, index, preorder, inorder);
        return n;
    }
};