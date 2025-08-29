// Last updated: 8/29/2025, 9:50:58 PM
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> res;
        int m = nums1.size(), n = nums2.size(), i = 0, j = 0;
        while(i < m && j < n){
            if(nums1[i] == nums2[j]){
                res.push_back(nums1[i]);
                i++;
                j++;
            } else if(nums1[i] < nums2[j]){
                i++;
            } else {
                j++;
            }
        }
        return res;
    }
};