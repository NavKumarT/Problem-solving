class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";
        int n = word1.length();
        int m = word2.length();
        int i = 0, j = 0;
        bool first = true;
        while(i < n && j < m){
            if(first){
                ans += word1[i];
                i++;
                first = !first;
            } else {
                ans += word2[j];
                j++;
                first = !first;
            }
        }
        while(i < n){
            ans += word1[i];
            i++;
        }
        while(j < m){
            ans += word2[j];
            j++;
        }
        return ans;
    }
};