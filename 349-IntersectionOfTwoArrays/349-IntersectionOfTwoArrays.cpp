// Last updated: 8/29/2025, 9:50:59 PM
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s;
        for(int num : nums1)
            s.insert(num);
        vector<int> arr;
        for(int i = 0; i < nums2.size(); i++){
            int num = nums2[i];
            // if(i > 0 && nums2[i] == nums2[i-1])
            //     continue;
            if(s.find(num) != s.end()){
                arr.push_back(num);
                s.erase(num);
            }
        }
        return arr;
    }
};