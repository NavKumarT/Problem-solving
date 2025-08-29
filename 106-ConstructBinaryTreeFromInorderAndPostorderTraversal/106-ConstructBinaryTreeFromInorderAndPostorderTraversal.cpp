// Last updated: 8/29/2025, 9:52:28 PM
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int i = inorder.size()-1;
        unordered_map<int, int> mp;
        for(int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i;
        return buildRecursive( inorder,  postorder,  0,  inorder.size()-1, i, mp);
    }

    TreeNode* buildRecursive(vector<int> &inorder, vector<int> &postorder, int left, int right, int &i, unordered_map<int, int> &mp){
        if(left > right)
            return NULL;
        TreeNode* node = new TreeNode(postorder[i]);
        int pos = 0;
        pos = mp[postorder[i]];
        // for(int x = 0; x <= postorder.size()-1; x++)
        //     if(postorder[i] == inorder[x])
        //         pos = x;
        i--;
        node->right =  buildRecursive( inorder,  postorder,  pos+1,  right, i, mp);
        node->left =  buildRecursive( inorder,  postorder,  left,  pos-1, i, mp);
        return node;
    }
};