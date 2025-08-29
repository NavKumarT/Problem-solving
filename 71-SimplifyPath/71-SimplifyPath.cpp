// Last updated: 8/29/2025, 9:52:52 PM
class Solution {
public:
    string simplifyPath(string path) {
        string ans = "/";
        string temp = "";
        stack<string> st;
        stack<string> reversedSt;
        for(char x : path){
            if(x == '/' && temp.length() == 0)
                continue;
            if(x == '/' && temp == ".."){
                if(st.empty() == false)
                    st.pop();
                temp = "";
            } else if(x == '/' && temp == "."){
                temp = "";
                continue;
            } else if(x == '/'){
                st.push(temp);
                temp = "";
            } else{
                temp += x;
            }
        }
        if(temp == ".."){
            if(st.empty() == false)
                st.pop();
        } else if(temp.length() > 0 && temp != "."){
            st.push(temp);
        }
        while(st.empty() == false){
            reversedSt.push(st.top());
            // ans += st.top();
            st.pop();
            // if(st.empty() == false)
            //     ans += "/";
        }
        while(reversedSt.empty() == false){
            // reversedSt.push(st.top());
            ans += reversedSt.top();
            reversedSt.pop();
            if(reversedSt.empty() == false)
                ans += "/";
        }
        return ans;
    }
};