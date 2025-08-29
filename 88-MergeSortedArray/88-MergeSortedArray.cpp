// Last updated: 8/29/2025, 9:52:40 PM
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int j = nums1.size()-1;
        m =  m-1;
        n = n-1;
        while(m >= 0 && n >= 0){
            if(nums1[m] >= nums2[n]){
                nums1[j] = nums1[m];
                m--;
                j--;
            } else {
                nums1[j] = nums2[n];
                n--;
                j--;
            }
        }
        while(n >= 0){
            nums1[j] = nums2[n];
            n--;
            j--;
        }
        while(m >= 0){
            nums1[j] = nums1[m];
            m--;
            j--;
        }
    }
};