// Last updated: 8/29/2025, 9:52:32 PM
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        bool order = true;
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if(root != NULL)
            q.push(root);
        while(q.empty() == false){
            vector<int> temp;
            int n = q.size();
            for(int i = 0; i < n; i++){
                TreeNode* node = q.front();
                q.pop();
                temp.push_back(node->val);
                if(node != NULL && node->left != NULL)
                    q.push(node->left);
                if(node != NULL && node->right != NULL)
                    q.push(node->right);
            }
            if(order == false)
                reverse(temp);
            order = !order;
            ans.push_back(temp);
        }
        return ans;
    }

    void reverse(vector<int> &vec){
        vector<int> r;
        for(int i = vec.size()-1; i>= 0; i--){
            r.push_back(vec[i]);
        }
        vec = r;
    }
};