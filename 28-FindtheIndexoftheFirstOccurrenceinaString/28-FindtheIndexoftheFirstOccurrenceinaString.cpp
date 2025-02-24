class Solution {
public:
    int strStr(string haystack, string needle) {
        int j = 0; // current index of the needle to compare
        int m = haystack.length();  // length of the haystack length 
        int n = needle.length(); // length of the needle length 
        int start = -1;
        for(int i = 0; i < m; ){
            int start = i;
            while(haystack[i] == needle[j]){
                i++;
                j++;
                if(j == n){
                    return i-n;
                } 
            }
            j = 0;
            i = start + 1;
        }
        return -1;
    }
};