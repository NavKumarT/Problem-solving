class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char x : s){
            if(x == '(' || x == '[' || x == '{'){
                st.push(x);
            } else {
                if(st.empty())
                    return false;
                char ch = st.top();
                st.pop();
                if(!isMatching(ch, x))
                    return false;
            }
        }
        if(!st.empty())
            return false;
        return true;
    }

    bool isMatching(char a, char b){
        if((a == '(' && b == ')') || (a == '{' && b == '}') || (a == '[' && b == ']'))
            return true;
        return false;
    }
};