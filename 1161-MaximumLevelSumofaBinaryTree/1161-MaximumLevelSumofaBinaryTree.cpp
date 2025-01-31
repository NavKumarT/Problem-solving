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
    int maxLevelSum(TreeNode* root) {
        int level = 1;
        int ans = 1;
        queue<TreeNode*> q;
        q.push(root);
        int maxLevelSum = INT_MIN;
        while(q.empty() == false){
            int n = q.size();
            int levelSum = 0;
            for(int i = 0; i < n; i++){
                TreeNode* node = q.front(); q.pop();
                levelSum += node->val;
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            if(levelSum > maxLevelSum){
                maxLevelSum = levelSum;
                ans = level;
            }
            level++;
        }
        return ans;
    }
};