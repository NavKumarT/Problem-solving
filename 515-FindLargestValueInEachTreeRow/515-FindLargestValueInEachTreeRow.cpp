// Last updated: 8/29/2025, 9:50:39 PM
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
    vector<int> largestValues(TreeNode* root) {
        if(root == nullptr)
            return {};
        vector<int> res;
        queue<TreeNode*> q;
        q.push(root);
        while(q.empty() == false){
            int n = q.size();
            int largest = INT_MIN;
            for(int k = 0; k < n; k++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left != nullptr)
                    q.push(node->left);
                if(node->right != nullptr)
                    q.push(node->right);
                largest = max(largest, node->val);
            }
            res.push_back(largest);
        }
        return res;
    }
};