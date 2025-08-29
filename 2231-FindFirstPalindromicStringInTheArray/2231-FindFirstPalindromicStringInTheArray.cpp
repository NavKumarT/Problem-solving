// Last updated: 8/29/2025, 9:48:33 PM
class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(string s : words){
            bool isPalindrome = true;
            for(int i = 0; i < s.length(); i++){
                if(s[i] != s[s.length()-1-i])
                  {isPalindrome = false;break;}
            }
            if(isPalindrome)
                return s;
        }
        return "";
    }
};