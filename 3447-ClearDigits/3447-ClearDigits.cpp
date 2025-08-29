// Last updated: 8/29/2025, 9:47:40 PM
class Solution {
public:
    string clearDigits(string s) {
        stack<char> st;
        for(char x : s){
            if(x < 48 || x > 57){
                st.push(x);
            }
            else if(st.empty() == false){
                st.pop();
            }
        }
        string ans = "";
        while(st.empty() == false){
            ans += st.top();
            st.pop();
        }
        if(ans.length() < 2)
            return ans;
        // REVERSE THE STRING 
        for(int i = 0; i < ans.length()/2; i++){
            char temp = ans[i];
            ans[i] = ans[ans.length()-1-i];
            ans[ans.length()-1-i] = temp;
        }
        return ans;
    }
};