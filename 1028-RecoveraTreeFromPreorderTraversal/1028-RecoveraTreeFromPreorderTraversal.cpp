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
    TreeNode* recoverFromPreorder(string traversal) {
        stack<pair<TreeNode*, int>> st;
        TreeNode* root = NULL;
        int dashes = 0;
        int number = 0;
        for(int i = 0; i < traversal.length(); i++){
            if(number == 0 && traversal[i] == '-'){
                dashes++;
                continue;
            } else if(isInt(traversal[i])){
                number = number * 10 + int(traversal[i]-48);
            } 
            else {
                while(st.empty() == false && st.top().second != dashes-1)
                    st.pop();
                cout << "NUmber : " << number << "dashes: " << dashes<< endl;
                // cout << st.top().first->val  << " " << dashes << " "  << traversal[i] << endl;
                TreeNode *node = new TreeNode(number);
                if(root == NULL){
                    root = node;
                    cout << "root created: " << node->val << endl;
                }
                else {
                    cout << "inside else " << st.size() << endl;
                    // cout << st.top() << " second" << endl;
                    TreeNode* parent  = st.top().first;
                    if(parent->left == NULL)
                    parent->left = node;
                else 
                    parent->right = node;
                    cout << node->val << " made either left or right of " << parent->val << endl;
                }
                cout << "pushed " << node->val << endl;
                st.push(make_pair(node, dashes));
                dashes = 1;
                number = 0;
            }
        }
        if(number != 0){
              while(st.empty() == false && st.top().second != dashes-1)
                    st.pop();
             TreeNode *node = new TreeNode(number);
                if(root == NULL){
                    root = node;
                    cout << "root created: " << node->val << endl;
                }
                else {
                    cout << "inside else " << st.size() << endl;
                    // cout << st.top() << " second" << endl;
                    TreeNode* parent  = st.top().first;
                    if(parent->left == NULL)
                    parent->left = node;
                else 
                    parent->right = node;
                    cout << node->val << " made either left or right of " << parent->val << endl;
                }

        }
        return root;
    }

    bool isInt(char num){
        return int(num) >= 48 && int(num) <= 57;
    }
};