// Last updated: 6/28/2026, 10:48:19 AM
1class Solution {
2public:
3    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
4        // for every point compute the distance from origin 
5
6        // add to a min heap 
7
8        // return the top k elements from the min heap 
9
10        // build min heap [n] + pick top k elements[klogk] = n time complexity since k <= n
11
12        // space is n since we are adding all the elements to the min heap 
13
14        // can we do better ? can we store only k elements using a maxheap of size k ? 
15
16        priority_queue<pair<double, vector<int>>> maxHeap;
17
18        for(vector<int> &point : points){
19            // get the distance 
20            double dist = getDistanceFromOrigin(point);
21
22            if(maxHeap.size() < k){
23                maxHeap.push(make_pair(dist, point));
24            } else {
25                if(dist < maxHeap.top().first){
26                    maxHeap.pop();
27                    maxHeap.push(make_pair(dist, point));
28                }
29            }
30        }
31
32        vector<vector<int>> kClosestPoints;
33        while(!maxHeap.empty()){
34            kClosestPoints.push_back(maxHeap.top().second);
35            maxHeap.pop();
36        }
37        return kClosestPoints;
38    }
39
40    double getDistanceFromOrigin(vector<int> &point){
41        int x = point[0];
42        int y = point[1];
43        cout << x << " " << y << " " << sqrt(x*x + y*y) << endl;
44
45        return sqrt(x*x + y*y);
46    }
47};