// Last updated: 8/29/2025, 9:49:28 PM
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(), trips.end(), comp);
        int current = 0;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq; 
        vector<int> vec = trips[0];
        pq.push(make_pair(vec[2], make_pair(vec[0], vec[1])));
        current += vec[0];
        if(current > capacity)
            return false;
        for(int i = 1; i < trips.size(); i++){
            while(pq.empty() == false){
                pair<int, pair<int, int>> p = pq.top();
                if(p.first <= trips[i][1]){
                    pq.pop();
                    current -= p.second.first;
                } else {
                    break;
                }
            }
            if(capacity - current < trips[i][0]){
                return false;
            } else {
                current += trips[i][0];
                pq.push(make_pair(trips[i][2], make_pair(trips[i][0], trips[i][1])));
            }
        }
        return true;
    }

    static bool comp(vector<int> a, vector<int> b){
        return a[1] < b[1];
    }
};