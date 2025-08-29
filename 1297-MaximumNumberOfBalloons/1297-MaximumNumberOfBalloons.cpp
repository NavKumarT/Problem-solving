// Last updated: 8/29/2025, 9:49:22 PM
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> mp;
        for(char ch : text)
            mp[ch]++;
        int countA = INT_MAX;
        int countB = INT_MAX;
        for(auto ch : "balloon"){
            if(ch == 'b' || ch == 'a' || ch == 'n')
                countA = min(countA, mp[ch]);
            else if(ch == 'l' || ch == 'o')
                countB = min(countB, mp[ch] / 2);
        }
        if(countA == INT_MAX || countB == INT_MAX)
            return 0;
        return min(countA, countB);
    }
};