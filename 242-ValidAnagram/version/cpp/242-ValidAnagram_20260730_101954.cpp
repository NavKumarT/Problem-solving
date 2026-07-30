// Last updated: 7/30/2026, 10:19:54 AM
1class Solution {
2public:
3    bool isAnagram(string s, string t) {
4        if(s.length() != t.length())
5            return false;
6        vector<int> occurences(26, 0);
7        for(int i = 0; i < s.length(); i++){
8            occurences[s[i]-'a']++;
9            occurences[t[i]-'a']--;
10        }
11        for(int count : occurences)
12            if(count != 0)
13                return false;
14        return true;
15    }
16};