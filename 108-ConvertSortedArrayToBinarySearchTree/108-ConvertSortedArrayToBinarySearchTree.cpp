// Last updated: 8/29/2025, 9:52:29 PM
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int low = 0, high = nums.size()-1;
        return convert(low, high, nums);
    }

    TreeNode* convert(int low, int high, vector<int> &nums){
        if(low > high)
            return nullptr;
        int mid = low + (high-low)/2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = convert(low, mid-1, nums);
        node->right = convert(mid+1, high, nums);
        return node;
    }
};