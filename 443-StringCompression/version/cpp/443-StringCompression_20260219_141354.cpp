// Last updated: 2/19/2026, 2:13:54 PM
1class Solution {
2public:
3    int compress(vector<char>& chars) {
4        int start = 0, count = 1;
5        for(int i = 1; i < chars.size(); i++){
6            if(chars[i] == chars[start]){
7                count++;
8            } else {
9                start++;
10                if(count > 1){
11                    vector<char> digits;
12            while(count){
13                digits.push_back('0' + (count%10));
14                count /= 10;
15            }
16            reverse(digits.begin(), digits.end());
17
18            for(char c : digits)
19                chars[start++] = c;
20                }
21                chars[start] = chars[i];
22                count = 1;
23            }
24        }
25        if(count > 1){
26            start++;
27            vector<char> digits;
28            while(count){
29                digits.push_back('0' + (count%10));
30                count /= 10;
31            }
32            reverse(digits.begin(), digits.end());
33            for(char c : digits)
34                chars[start++] = c;
35        }
36        return count == 1 ? start+1 : start;
37    }
38};