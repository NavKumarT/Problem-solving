// Last updated: 8/29/2025, 9:53:27 PM
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0, end = 0;
        int ans = 0;
        vector<int> count(256, 0);
        for(int i  = 0; i < s.length(); i++){
            end = i;
            count[s[i]]++;
            if(count[s[i]] == 1){
                ans = max(ans, end-start+1);
            } else {
                while(count[s[i]] > 1)
                    count[s[start++]]--;
            }
        }
        return ans;
    }
};