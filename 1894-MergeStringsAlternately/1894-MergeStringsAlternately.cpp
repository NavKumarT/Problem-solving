// Last updated: 8/29/2025, 9:48:49 PM
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i = 0,  j = 0;
        int m = word1.length(), n = word2.length();
        string temp = "";
        bool isFirst = true;
        while(i < m && j < n){
            if(isFirst){
                temp += word1[i]; 
                i++;
                isFirst = !isFirst;
            } else {
                temp += word2[j]; 
                j++;
                isFirst = !isFirst;
            }
        }
        while(i < m){
            temp += word1[i]; 
                i++;
        }
        while(j < n){
            temp += word2[j]; 
                j++;
        }
        return temp;
    }
};