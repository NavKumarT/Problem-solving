// Last updated: 8/29/2025, 9:51:30 PM
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> traversal;
        if(root == nullptr)
            return traversal;
        queue<TreeNode*> q;
        q.push(root);
        while(q.empty() == false){
            int size = q.size();
            for(int i = 0; i < size; i++){
                TreeNode* n = q.front(); q.pop();
                if(n->left != nullptr)
                    q.push(n->left);
                if(n->right != nullptr)
                    q.push(n->right);
                if(i == size-1)
                traversal.push_back(n->val);
            }
        }
        return traversal;
    }
};