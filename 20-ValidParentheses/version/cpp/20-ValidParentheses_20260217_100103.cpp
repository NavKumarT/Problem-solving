// Last updated: 2/17/2026, 10:01:03 AM
1class Solution {
2public:
3    bool isValid(string s) {
4        stack<char> st;
5        for(char ch : s){
6            if(ch == '(' || ch == '{' || ch == '['){
7                st.push(ch);
8            } else {
9                if(st.empty())
10                    return false;
11                char top = st.top();
12                st.pop();
13                if(!isMatching(top, ch))
14                    return false;
15            }
16        }
17        return st.empty();
18    }
19
20    bool isMatching(char opening, char closing){
21        if((opening == '(' && closing == ')') || (opening == '[' && closing == ']') || (opening == '{' && closing == '}')){
22            return true;
23        } else {
24            return false;
25        }
26    }
27};