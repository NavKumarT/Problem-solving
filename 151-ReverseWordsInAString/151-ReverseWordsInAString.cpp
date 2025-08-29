// Last updated: 8/29/2025, 9:51:40 PM
class Solution {
public:
    string reverseWords(string s) {
        // reverse the words 
        // reverse the whole string 
        int start = 0;
        int end;
        for( end = 0; end < s.length(); end++){
            if(s[end] == ' '){
                reverse(s, start, end-1);
                start = end+1;
            }
        }
        reverse(s, start, end-1);
        reverse(s, 0, s.length()-1);
        string ans = "";
        for(char x : s){
            if(ans.length() > 0 && x == ' ' && ans.back() != ' ')
                ans += x;
            else if(x != ' ')
                ans += x;
        }
        if(ans.rfind(' ') == ans.length()-1)
            ans = ans.substr(0, ans.length()-1);
        return ans;
    }


    void reverse(string &s, int start, int end){
        while(start < end){
            char temp = s[start];
            s[start] = s[end];
            s[end] = temp;
            start++;
            end--;
        }
    }
};