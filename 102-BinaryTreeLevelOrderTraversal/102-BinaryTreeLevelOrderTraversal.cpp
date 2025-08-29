// Last updated: 8/29/2025, 9:52:33 PM
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> traversal;
        if(root == nullptr)
            return traversal;
            queue<TreeNode*> q;
            q.push(root);
            while(q.empty() == false){
                int size = q.size();
                vector<int> temp;
                for(int i = 0; i < size; i++){
                    TreeNode* n = q.front(); q.pop();
                    if(n->left != nullptr)
                        q.push(n->left);
                    if(n->right != nullptr)
                        q.push(n->right);
                    temp.push_back(n->val);
                }
                traversal.push_back(temp);
            }
            return traversal;
    }
};