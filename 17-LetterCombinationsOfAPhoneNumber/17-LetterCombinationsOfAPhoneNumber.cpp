// Last updated: 8/29/2025, 9:53:23 PM
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        string curr;
        int i = 0;
       unordered_map<char, string> digitToLetters = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
        };

        backtracking(curr, res, i, digits.size(), digits, digitToLetters);
        return res;
    }


    void backtracking(string curr,vector<string> &ans, int i, int n, string digits, unordered_map<char, string> &mp){
        if(i == digits.size()){
            if(curr.length() > 0)
                ans.push_back(curr); 
            return;
        }
        string letters = mp[digits[i]];
        for(char ch : letters){
            curr += ch;
            backtracking(curr, ans, i+1,n,  digits, mp);
            curr = curr.substr(0, curr.length()-1);
        }
    }
};