// Last updated: 8/29/2025, 9:50:01 PM
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<double> st;
        // sort positon and speed accrding to the speed 
        vector<pair<int, int>> zippedVector;
        for(int i = 0; i < position.size(); i++){
            zippedVector.push_back(make_pair(position[i], speed[i]));
        }
        // sort the zipped vector
        auto comp = [](pair<int, int> a, pair<int, int> b){
            return a.first < b.first;
        };
        sort(zippedVector.begin(), zippedVector.end(), comp);
        for(int i = position.size()-1 ; i >= 0; i--){
            double temp;
            temp = double(target - zippedVector[i].first) / zippedVector[i].second;
            if(st.empty())
                st.push(temp);
            else if(st.top() < temp)
                st.push(temp);
        }
        return st.size();
    }
};