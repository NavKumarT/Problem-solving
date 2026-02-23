// Last updated: 2/23/2026, 4:30:07 PM
1class Solution {
2public:
3    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
4        priority_queue<tuple<double, int, int>> pq;
5        for(vector<int> point : points){
6            double distance = getDistance(point);
7            if(pq.size() < k){
8                pq.push({distance, point[0], point[1]});
9            } else {
10                if(get<0>(pq.top()) > distance){
11                    pq.pop();
12                    pq.push({distance, point[0], point[1]});
13                }
14            }
15        }
16        vector<vector<int>> r;
17        while(pq.empty() == false){
18            int x = get<1>(pq.top());
19            int y = get<2>(pq.top());
20            r.push_back({x, y});
21            pq.pop();
22        }
23        return r;
24    }
25
26    double getDistance(vector<int> point){
27        int x = point[0], y = point[1];
28        return sqrt(pow(x, 2) + pow(y, 2));
29    }
30};