// Last updated: 8/29/2025, 9:50:16 PM
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        stack<int> s;
        for(int x : a){
            if(x < 0 && (s.empty() || s.top() < 0)){
                s.push(x);
            } else if (s.empty() == false && s.top() > 0 && x < 0){
                while(s.empty() == false && s.top() > 0 && abs(s.top()) < abs(x))
                    s.pop();
                if(s.empty() == false && s.top() > 0 && abs(s.top()) == abs(x))
                    s.pop();
                else if(s.empty() || s.top() < 0 )
                    s.push(x);
            } else if( x > 0) {
                s.push(x);
            }
        }
        vector<int> ans(s.size(), 0);
        for(int i = s.size()-1; i >=0 ; i--){
            int temp = s.top();
            s.pop();
            ans[i] = temp;
        }
        return ans;
    }
};