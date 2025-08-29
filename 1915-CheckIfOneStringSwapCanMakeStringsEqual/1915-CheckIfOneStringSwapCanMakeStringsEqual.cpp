// Last updated: 8/29/2025, 9:48:48 PM
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.length();
        unordered_map<char, int> mp;
        int count = 0;
        for(int i = 0; i < n; i++){
            if(count > 2)
                return false;
            if(s1[i] != s2[i]){
                mp[s1[i]]++;
                mp[s2[i]]--;
                count++;
            }
        }
        if(!(mp.size() == 2 || mp.size() == 0))
            return false;
        for(auto it : mp){
            if(it.second != 0)
                return false;
        }
        return true;

    }
};