// Last updated: 22/04/2025, 12:25:35
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
    TreeNode* replaceValueInTree(TreeNode* root) {
        // make 2 level order traversals 
        // first one to store the sum of the levels 
        // second one to change the node values 
        if(root == nullptr)
            return root;
        queue<TreeNode*> q;
        vector<int> levelSum;
        int level = 0;
        q.push(root);
        while(q.empty() == false){
            int n = q.size();
            int sum = 0;
            for(int i = 0; i < n; i++){
                TreeNode* node = q.front();
                q.pop();
                sum += node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            levelSum.push_back(sum);
        }
        cout << "here " << endl;
        level = 0;
        queue<pair<TreeNode*, int>> qq;
        qq.push(make_pair(root, root->val));
        while(qq.empty() == false){
            int n = qq.size();
            for(int i = 0; i < n; i++){
                pair<TreeNode*, int> pp = qq.front();
                qq.pop();
                TreeNode* node = pp.first;
                int siblingSum = pp.second;
                node->val = levelSum[level] - siblingSum;
                cout << levelSum[level] - siblingSum << endl;
                int sum = 0;
                if(node->left) sum += node->left->val;
                if(node->right) sum += node->right->val;
                if(node->left) qq.push(make_pair(node->left, sum));
                if(node->right)  qq.push(make_pair(node->right, sum));
            }
            level++;
        }
        return root;
    }
};