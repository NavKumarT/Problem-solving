// Last updated: 21/04/2025, 19:09:20
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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, unsigned long long>> q;
        unsigned long long ans = 0;
        q.push(make_pair(root, 1));
        if(root == nullptr)
            return 0;
        while(q.empty() == false){
            int n = q.size();
            unsigned long long left = -1, right = -1;
            for(int i = 0 ; i < n; i++){
                pair<TreeNode*, unsigned long long> p = q.front();
                q.pop();
                unsigned long long k = p.second; // the int value associated with each node: k , 2k+1, 2k+2
                TreeNode* node = p.first; // the node we popped 
                if(i == 0)
                    left = k;
                if(i == n-1)
                    right = k;
                if(node->left != nullptr)
                    q.push(make_pair(node->left, 2 * k +1));
                if(node->right != nullptr)
                    q.push(make_pair(node->right, 2 * k +2));
            }
            if(right == -1 || left == -1){
                ans = max(ans, (unsigned long long)1);
            }
            else {
                ans = max(ans, right-left+1);
            }
        }
        return ans;
    }
};