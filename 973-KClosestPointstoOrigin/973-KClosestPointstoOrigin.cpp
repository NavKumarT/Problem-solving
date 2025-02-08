class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>> , vector<pair<int, vector<int>>>, greater<>> pq;
        for(int i = 0; i < points.size(); i++){
            int dist = points[i][0] * points[i][0] + points[i][1]*points[i][1];
            pq.push(make_pair(dist, points[i]));
        }
        vector<vector<int>> ans;
        for(int i = 0; i < k ; i++){
            pair<int, vector<int>> point = pq.top();
            pq.pop();
            ans.push_back(point.second);
        }
        return ans;
    }
};