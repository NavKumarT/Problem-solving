// Last updated: 8/29/2025, 9:48:24 PM
class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> indices;
        unordered_set<int> s;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == key){
                int left = i-k;
                int right = i+k;
                s.insert(i);
                while(left < i){
                    if(left >= 0)
                        s.insert(left);
                    left++;
                }
                while(right > i){
                    if(right < nums.size())
                        s.insert(right);
                    right--;
                }
            }
        }
        for(auto it : s)
        indices.push_back(it);
        sort(indices.begin(), indices.end());
        return indices;
    }

};