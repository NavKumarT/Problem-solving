// Last updated: 8/29/2025, 9:48:58 PM
class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        pair<int, int> p;
        p.first = -1;
        p.second = -1;
        vector<pair<int, int>> temp(26, p);
        int ans = -1;
        for(int i = 0; i < s.length(); i++){
            pair<int, int> occurences = temp[s[i]-97];
            if(occurences.first == -1)
                occurences.first = i;
            else
                occurences.second = i;
            if(occurences.second != -1)
                ans = max(ans,  occurences.second - occurences.first - 1) ;
            temp[s[i]-97] = occurences;
        }
        return ans;
    }
};