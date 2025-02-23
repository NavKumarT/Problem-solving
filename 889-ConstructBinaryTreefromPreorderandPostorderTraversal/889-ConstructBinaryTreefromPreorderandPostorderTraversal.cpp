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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        unordered_set<int> visited;
        unordered_map<int, int> postOrderIndex;
        int n = postorder.size();
        for(int i = 0; i < n; i++){
            postOrderIndex[postorder[i]] = i;
        }
        return utilsFunc(preorder, postorder, postOrderIndex, n, 0, visited, 0, n-1);
    }

    TreeNode* utilsFunc(vector<int> &preorder, vector<int> &postorder, unordered_map<int, int> &mp, int n, int index, unordered_set<int> &s, int start, int end){
        int val = preorder[index];
        s.insert(val);
        TreeNode* node = new TreeNode(val);

        cout << "create node for " << val << endl;
        if(start >= end)
            return node;
        
        int leftVal = -1;
        int leftindex = -1;
        for(int i = index+1;i < n; i++){
            if(s.find(preorder[i]) == s.end() && mp[preorder[i]] < mp[val]){
                leftVal = preorder[i];
                leftindex = i;
                break;
            }
        }
        if(leftVal == -1 || leftindex == -1)
            return node;
        
        cout << "calling left of " << val << " : " << start << " " << mp[leftVal]-1 << " - " << "left val " << leftVal << endl;
        node->left = utilsFunc(preorder, postorder, mp, n, leftindex, s, start, mp[leftVal]);

int rightval = -1;
        int rightindex = -1;
        for(int i = index+1;i < n; i++){
            if(s.find(preorder[i]) == s.end() && mp[preorder[i]] < mp[val]){
                rightval = preorder[i];
                rightindex = i;
                break;
            }
        }
        if(rightval == -1 || rightindex ==-1)
            return node;
        cout << "calling right of " << val << " : " << start << " " << mp[leftVal]-1 << " - " << "right val " << rightval << endl;

        node->right = utilsFunc(preorder, postorder, mp, n, rightindex, s, mp[leftVal]+1, mp[rightval]);

        return node;




    }
};