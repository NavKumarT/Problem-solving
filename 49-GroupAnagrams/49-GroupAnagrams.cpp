// Last updated: 8/29/2025, 9:53:02 PM
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(string str : strs){
            string temp = str;
            sort(temp.begin(), temp.end());
            if(mp.find(temp) != mp.end()){
                mp[temp].push_back(str);
            } else {
                mp[temp] = {str};
            }
        }
        vector<vector<string>> res;
        for(auto it : mp){
            vector<string> temp;
            for(string str : it.second)
                temp.push_back(str);
            res.push_back(temp);
        }
        return res;
    }
};