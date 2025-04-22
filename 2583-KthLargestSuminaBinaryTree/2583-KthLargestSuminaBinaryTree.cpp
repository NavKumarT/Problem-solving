// Last updated: 22/04/2025, 12:53:24
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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        // Get the level sum by doing a level order traversal
        // Insert the levelSum in a maxheap
        // Pop k-1 times from the maxheap 
        // Return the root of the maxheap 
        queue<TreeNode*> q;
        priority_queue<long long> pq;
        q.push(root);
        while(q.empty() == false){
            long long n = q.size(); // size of the current level
            long long sum = 0; // sum of all the node of the level 
            for(long long i = 0; i < n; i++){
                TreeNode* node = q.front();
                q.pop();
                sum += node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            pq.push(sum);
        }
        while(k > 1 && pq.empty() != true){
            pq.pop();
            k--;
        }
        // if the number of levels in the tree are less than k
        if(pq.empty() == true)
            return -1;
        return pq.top();
    }
};