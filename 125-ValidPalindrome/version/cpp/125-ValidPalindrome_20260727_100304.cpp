// Last updated: 7/27/2026, 10:03:04 AM
1class Solution {
2public:
3    bool isPalindrome(string s) {
4        int start = 0, end = s.length()-1;
5        int length = s.length();
6        while(start < end){
7            while(start < length && !isalnum(s[start]))
8                start++;
9            while(end >= 0 && !isalnum(s[end]))
10                end--;
11            if(start > end)
12                return true;
13            if(tolower(s[start]) != tolower(s[end]))
14                return false;
15            start++;
16            end--;
17        }
18        return true;
19    }
20};