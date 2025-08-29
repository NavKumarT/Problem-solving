// Last updated: 8/29/2025, 9:48:15 PM
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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;
        if(root == nullptr)
            return root;
        q.push(root);
        int level = 0;
        while(q.empty() == false){
            int n = q.size();
            vector<TreeNode*> vec;
            for(int i = 0; i < n; i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left != nullptr)
                    q.push(node->left);
                if(node->right != nullptr)
                    q.push(node->right);
                vec.push_back(node);
            }
            if(level % 2 != 0){
                int n = vec.size();
                for(int i = 0; i < n/2; i++){
                    int temp = vec[i]->val;
                    vec[i]->val = vec[n-1-i]->val;
                    vec[n-i-1]->val = temp;
                }
            }
            level++;
        }
        return root;
    }
};