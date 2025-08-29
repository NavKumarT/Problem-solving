// Last updated: 8/29/2025, 9:49:45 PM
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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        while(q.empty() == false){
            TreeNode* node = q.front();
            q.pop();
            if(node == NULL){
                TreeNode *temp;
                while(q.empty() == false && q.front() == NULL)
                    q.pop();
                if(q.size() != 0)
                    return false;
                else return true;
            } else {
                q.push(node->left);
                q.push(node->right);
            }
        }
        return true;
    }

};