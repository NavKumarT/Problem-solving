// Last updated: 8/29/2025, 9:48:30 PM
class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        string temp = "";
        vector<string> res;
        for(char ch : s){
            if(temp.size() < k)
                temp += ch;
            if(temp.length() == k){
                res.push_back(temp);
                temp = "";
            }
        }
        while(temp.length() != 0 && temp.length() < k)
            temp += fill;
        if(temp.length() != 0)
            res.push_back(temp);
        return res;
    }
};