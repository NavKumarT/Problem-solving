// Last updated: 8/29/2025, 9:49:43 PM
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double, vector<int>>> pq;
        for(auto point : points){
            double distance = getDistance(point);
            if(pq.size() < k)
                pq.push(make_pair(distance, point));
            else if(pq.top().first > distance){
                pq.pop();
                pq.push(make_pair(distance, point));
            }
        }
        vector<vector<int>> res;
        while(pq.empty() == false){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }

    double getDistance(vector<int> point){
        int x = point[0], y = point[1];
        double dist =  sqrt(x*x + y*y);
        return dist;
    }
};