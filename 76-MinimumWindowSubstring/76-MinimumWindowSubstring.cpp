// Last updated: 8/29/2025, 9:52:49 PM
class Solution {
public:

    string minWindow(string s, string t) {
        int start = 0, end = 0;
        unordered_map<char, int> mp;
        int size = INT_MAX;
        int finalStart, finalEnd;
        unordered_map<char, int> mp_fixed;
        for(char ch : t)
            mp_fixed[ch]++;
        int have = 0, need = mp_fixed.size();
        for(int i = 0; i < s.length(); i++){
            end = i;
            mp[s[end]]++;
            if(mp_fixed.count(s[end]) && mp_fixed[s[end]] == mp[s[end]])
            have++;
            while(have >= need && start < s.length()){
                if(end-start+1 < size){
                    size = end-start+1;
                    finalStart = start;
                    finalEnd = end;
                }
                mp[s[start]]--;
                if(mp_fixed.count(s[start]) && mp_fixed[s[start]] >  mp[s[start]])
                have--;
                if(mp[s[start]] == 0)
                    mp.erase(s[start]);
                start++;
            }
        }
        return size == INT_MAX ? "" : s.substr(finalStart, finalEnd-finalStart+1);
    }
};