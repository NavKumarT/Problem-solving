// Last updated: 8/29/2025, 9:50:28 PM
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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // for every node in the main tree, compare that with the subroot 
        // we need a traversal algo and one function to compare;
        return traversal(root, subRoot);
    }

    bool traversal(TreeNode* root, TreeNode*subroot){
        if(root == NULL && subroot != NULL)
            return false;
        bool ans = compareRoots(root, subroot);
        if(ans == true)
            return ans;
        return traversal(root->left, subroot) || traversal(root->right, subroot);
    }

    bool compareRoots(TreeNode* root1, TreeNode* root2){
        if(root1 == NULL && root2 == NULL)
            return true;
        else if((root1 == NULL && root2 != NULL) || (root2 == NULL && root1 != NULL))
            return false;
        else if(root1->val != root2->val)
            return false;
        bool left = compareRoots(root1->left, root2->left);
        bool right = compareRoots(root1->right, root2->right);
        return left && right;
    }
};