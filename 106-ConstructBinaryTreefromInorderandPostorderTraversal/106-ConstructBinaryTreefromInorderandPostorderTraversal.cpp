// Last updated: 28/04/2025, 18:50:15
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int i = inorder.size()-1;
                return buildRecursive( inorder,  postorder,  0,  inorder.size()-1, i);
    }

    TreeNode* buildRecursive(vector<int> inorder, vector<int> postorder, int left, int right, int &i){
        if(left > right)
            return NULL;
        TreeNode* node = new TreeNode(postorder[i]);
        int pos = 0;
        for(int x = 0; x <= postorder.size()-1; x++)
            if(postorder[i] == inorder[x])
                pos = x;
        i--;
        node->right =  buildRecursive( inorder,  postorder,  pos+1,  right, i);
        node->left =  buildRecursive( inorder,  postorder,  left,  pos-1, i);
        return node;
    }
};