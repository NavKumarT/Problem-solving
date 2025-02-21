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
class FindElements {
private: 
    unordered_set<int> s;

public:
    FindElements(TreeNode* root) {
        root->val = 0;
        queue<TreeNode*> q;
        s.insert(root->val);
        q.push(root);
        while(q.empty() == false){
            TreeNode* node = q.front();
            q.pop();
            if(node->right){
                node->right->val = node->val * 2 + 2;
                s.insert(node->right->val);
                q.push(node->right);
            }
            if(node->left){
                node->left->val = node->val * 2 + 1;
                s.insert(node->left->val);
                q.push(node->left);
            }
        }
    }
    
    bool find(int target) {
        return s.find(target) != s.end();
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */