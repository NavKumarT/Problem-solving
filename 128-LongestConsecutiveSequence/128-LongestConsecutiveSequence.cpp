// Last updated: 8/29/2025, 9:52:20 PM
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        unordered_set<int> s;
        for(int num : nums)
            s.insert(num);
        // for(int i = 0 ; i < nums.size(); i++){
        //     if(s.find(nums[i]-1) == s.end()){
        //         int count = 1;
        //         while(s.find(nums[i]+count) != s.end())
        //             count++;
        //         res = max(res, count);
        //     }
        // }
        for(auto it : s){
            if(s.find(it-1) == s.end()){
                int count = 1;
                while(s.find(it+count) != s.end()){
                    count++;
                }
                res = max(res, count);
            }
        }
        return res;
    }
};