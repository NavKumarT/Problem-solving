// Last updated: 8/29/2025, 9:50:00 PM
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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leafSequence1;
        vector<int> leafSequence2;
        buildLeadSequence(root1, leafSequence1);
        buildLeadSequence(root2, leafSequence2);
        return areSameVectors(leafSequence1, leafSequence2);
    }

    bool areSameVectors(vector<int> vector1, vector<int> vector2){
        int m = vector1.size();
        int n = vector2.size();
        if(m != n)
            return false;
        for(int i = 0; i < m; i++){
            if(vector1[i] != vector2[i])
                return false;
        }
        return true;
    }

    void buildLeadSequence(TreeNode* root, vector<int> &leafSequence){
        if(root == NULL)
            return;
        if(root->left == NULL && root->right == NULL){
            leafSequence.push_back(root->val);
            return;
        }
        buildLeadSequence(root->left, leafSequence);
        buildLeadSequence(root->right, leafSequence);
    }
};