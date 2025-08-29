// Last updated: 8/29/2025, 9:50:15 PM
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<int> st;
        vector<int> ans(temp.size(), 0);
        st.push(temp.size()-1);
        // ans.push_back(0);
        for(int i = temp.size()-2; i >= 0; i--){
            while(st.empty() == false && temp[st.top()] <= temp[i])
                st.pop();
            if(st.empty()) {
                ans[i] =  0; 
            } else {
                ans[i] = st.top() - i;
            }
            st.push(i);
        }
        return ans;
    }
};