// Last updated: 8/29/2025, 9:48:32 PM
class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string temp = "";
        int i = 0;
        for(int j = 0; j < s.length(); j++){
            if(i < spaces.size() && j == spaces[i]){
                temp += " ";
                i++;
            }
            temp += s[j];
        }
        return temp;
    }
};