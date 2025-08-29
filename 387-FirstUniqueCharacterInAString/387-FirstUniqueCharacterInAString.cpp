// Last updated: 8/29/2025, 9:50:54 PM
class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> alphabets(26, 0);
        for(char x : s){
            alphabets[x-97]++;
        }
        for(int i = 0; i < s.length(); i++){
            if(alphabets[s[i]-97] == 1)
                return i;
        }
        return -1;
    }
};