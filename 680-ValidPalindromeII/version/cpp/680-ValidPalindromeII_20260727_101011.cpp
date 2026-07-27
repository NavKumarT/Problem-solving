// Last updated: 7/27/2026, 10:10:11 AM
1class Solution {
2public:
3    bool validPalindrome(string s) {
4        int start = 0, end = s.length()-1;
5         while(start < end){
6            if(s[start] != s[end]){
7                return checkValidPalindrome(s, start+1, end) || checkValidPalindrome(s, start, end-1);
8            }
9            start++;
10            end--;
11        }
12        return true;
13    }
14
15    bool checkValidPalindrome(string s, int start, int end){
16        while(start < end){
17            if(s[start] != s[end])
18                return false;
19            start++;
20            end--;
21        }
22        return true;
23    }
24};