// Last updated: 2/19/2026, 6:53:47 PM
1class Solution {
2public:
3    string longestPalindrome(string s) {
4        int n = s.length();
5        int maxLength = 1, start = 0, end = 0;
6        vector<vector<bool>> memo(n, vector<bool> (n, false));
7        for(int i = n-1; i >= 0; i--){
8            for(int j = i; j < n; j++){
9                if(i == j)
10                    memo[i][j] = true;
11                else if(j == i+1 && s[i] == s[j]){
12                    memo[i][j] = true;
13                    if(j-i+1 > maxLength){
14                        start = i;
15                        end = j;
16                        maxLength = j-i+1;
17                    }
18                }
19                else if(s[i] == s[j] && memo[i+1][j-1]){
20                    memo[i][j] = true;
21                    if(j-i+1 > maxLength){
22                        start = i;
23                        end = j;
24                        maxLength = j-i+1;
25                    }
26                }
27            }
28        }
29        return s.substr(start, end-start+1);
30    }
31};