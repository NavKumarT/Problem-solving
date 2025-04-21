// Last updated: 21/04/2025, 16:25:59
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
        queue<pair<TreeNode*, long long>> q;
        q.push(make_pair(root, 1));
        unsigned long long  ans = 0;
        unsigned long long  count = 0;
        unsigned long long  prevWidth = 0;
        while(q.empty() == false){
            int n = q.size();
            unsigned long long power = prevWidth + 1;
            unsigned long long front = 0;
            for(int i = 0 ; i < n; i++){
                pair<TreeNode*, long long int> n = q.front();
                q.pop();
                unsigned long long val = n.second;
                prevWidth = val;
                TreeNode* node = n.first;         
                if(front == 0)
                    front = val;
                if(front == 0)
                    ans = max(ans, val - power +1 );
                else 
                    ans = max(ans, val - front +1 );
                if(node != NULL){
                    if(node->left != NULL){
                        q.push(make_pair(node->left, 2 * val));
                    }
                    if(node->right != NULL){
                        q.push(make_pair(node->right, 2 * val + 1));
                    }
                }
            }   
            count++; 
        }
        return ans;
    }
};