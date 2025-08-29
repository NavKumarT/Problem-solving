// Last updated: 8/29/2025, 9:50:41 PM
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        unordered_map<int, int> mp;
        mp[nums2[nums2.size()-1]] = -1;
        s.push( nums2[nums2.size()-1]);
        for(int i = nums2.size()-1; i >= 0; i--){
            int temp = nums2[i];
            while(!s.empty() && s.top() <= nums2[i]){
                s.pop();
            }
            if(s.empty())
                mp[nums2[i]] = -1;
            else
                mp[nums2[i]] = s.top();
            s.push(temp);
        }
        vector<int> ans;
        for(int i : nums1)
            ans.push_back(mp[i]);
        return ans;
    }
};