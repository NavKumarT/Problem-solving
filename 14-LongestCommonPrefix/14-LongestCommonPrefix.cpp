class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 1)
            return strs[0];
        string sub = func(strs[0], strs[1]);
        for(int i = 1; i < strs.size(); i++){
            sub = func(sub, strs[i]);
        }
        return sub;
    }

    string func(string s1, string s2){
        int m = s1.length();
        int n = s2.length();
        int i = 0; 
        int j = 0;
        string ans = "";
        while(i < m && j < n){
            if(s1[i] == s2[j]){
                ans += s1[i];
                i++;
                j++;
            } else if(s1[i] != s2[j]){
                break;
            }
        }
        return ans;
    }
};