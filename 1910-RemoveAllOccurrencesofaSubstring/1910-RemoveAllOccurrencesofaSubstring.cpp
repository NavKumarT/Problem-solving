class Solution {
public:
    string removeOccurrences(string s, string part) {
        stack<char> st;
        int n = s.length();
        int m = part.length();
        for(char x : s){
            st.push(x);
            if(st.size() >= m && part[m-1] == st.top()){
                int i = 0;
                string temp = "";
                while(i < m){
                    if(st.top() != part[m-1-i])
                        break;
                    temp = st.top() + temp;
                    st.pop();
                    i++;
                }
                if(temp == part)
                    continue;
                else {
                    for(int i = 0; i < temp.size(); i++){
                        st.push(temp[i]);
                    }
                }
            }
        }
        string ans = "";
        while(st.empty() == false){
            ans  = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};