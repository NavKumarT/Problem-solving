// Last updated: 2/17/2026, 6:51:53 PM
1class Solution {
2public:
3    string reverseWords(string s) {
4        stack<char> st;
5        for(char ch : s)
6            st.push(ch);
7        string temp = "";
8        string n = "";
9        while(st.empty() == false){
10            while(st.empty() == false && st.top() == ' '){
11                st.pop();
12            }
13            while(st.empty() == false && isalnum(st.top())){
14                temp += st.top();
15                st.pop();
16            }
17            
18            if(temp.length() > 0){
19                reverse(temp.begin(), temp.end());
20                if(n.length() > 0)
21                    n += " ";
22                n += temp;
23                temp = "";
24            }
25        }
26        return n;
27    }
28};