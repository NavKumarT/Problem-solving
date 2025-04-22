// Last updated: 22/04/2025, 15:52:48
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
    int goodNodes(TreeNode* root) {
        int count  = 0;
        int largest = INT_MIN;
        traversal(root, largest, count);
        return count;
    }

    void traversal(TreeNode* root, int largest, int &count){
        if(root == nullptr)
            return;
        if(root->val >= largest){
            count++;
            largest = root->val;
        }
        traversal(root->left, largest, count);
        traversal(root->right, largest, count);
    }
};