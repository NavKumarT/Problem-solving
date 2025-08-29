// Last updated: 8/29/2025, 9:48:59 PM
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
    bool isEvenOddTree(TreeNode* root) {
        int level = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(q.empty() == false){
            int n = q.size();
            int minimumSoFar = INT_MIN;
            int maxSoFar = INT_MAX;
            for(int i = 0 ; i < n; i++){
                TreeNode* node = q.front();
                q.pop();
                if((level % 2 == 0 && (node->val % 2 == 0 || node->val <= minimumSoFar)) || (level % 2 != 0  && (node->val % 2 != 0 || node->val >= maxSoFar))){
                        return false;
                }
                minimumSoFar = node->val;
                maxSoFar = node->val;
                if(node != NULL && node->left != NULL )
                    q.push(node->left);
                if(node != NULL && node->right != NULL)
                    q.push(node->right);
            }
            level++;
        }
        return true;
    }
};