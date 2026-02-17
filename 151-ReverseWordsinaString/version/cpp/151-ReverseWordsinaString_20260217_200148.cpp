// Last updated: 2/17/2026, 8:01:48 PM
1class Solution {
2public:
3    string reverseWords(string s) {
4        // stack<char> st;
5        // for(char ch : s)
6        //     st.push(ch);
7        // string temp = "";
8        // string n = "";
9        // while(st.empty() == false){
10        //     while(st.empty() == false && st.top() == ' '){
11        //         st.pop();
12        //     }
13        //     while(st.empty() == false && isalnum(st.top())){
14        //         temp += st.top();
15        //         st.pop();
16        //     }
17            
18        //     if(temp.length() > 0){
19        //         reverse(temp.begin(), temp.end());
20        //         if(n.length() > 0)
21        //             n += " ";
22        //         n += temp;
23        //         temp = "";
24        //     }
25        // }
26        // return n;
27        int n = s.length();
28        int actual = 0;
29        int start = 0, end = 0;
30        for(int i = 0 ; i < n; i++){
31            while(i < n && s[i] == ' ')
32                i++;
33            if(i >= n)
34                break;
35            if(actual > 0)
36                s[actual++] = ' ';
37            start = actual;
38            while(i < n && s[i] != ' ')
39                s[actual++] = s[i++];
40            end = actual-1;
41            reverse(s, start, end);
42        }
43        s.resize(actual);
44        reverse(s, 0, actual-1);
45        return s;
46    }
47
48    void reverse(string &s, int start, int end){
49        while(start < end){
50            swap(s[start], s[end]);
51            start++;
52            end--;
53        }
54    }
55};