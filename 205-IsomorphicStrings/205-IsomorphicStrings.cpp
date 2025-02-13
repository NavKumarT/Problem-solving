class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mp1;
        unordered_set<char> ss;
        if(s.length() != t.length())
            return false;
        for(int i = 0; i < s.length(); i++){
            char x = s[i];
            if((mp1.find(x) != mp1.end() && mp1[x] != t[i]) || ( mp1[x] != t[i] && ss.find(t[i]) != ss.end()))
                return false;
            else {
                mp1[x] = t[i];
                // mp2[t[i]] = x;
                ss.insert(t[i]);
            }
        }
        return true;
    }
};