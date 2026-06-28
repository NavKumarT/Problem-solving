// Last updated: 6/28/2026, 10:52:48 AM
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
16        priority_queue<pair<int, int>> maxHeap;
17
18        for(int i = 0; i < points.size(); i++){
19            // get the distance 
20            int x = points[i][0];
21            int y = points[i][1];
22            int dist = x*x + y*y; 
23            // x, y <= 10**4 so will not overflow int
24
25            if(maxHeap.size() < k){
26                maxHeap.push(make_pair(dist, i));
27            } else {
28                if(dist < maxHeap.top().first){
29                    maxHeap.pop();
30                    maxHeap.push(make_pair(dist, i));
31                }
32            }
33        }
34
35        vector<vector<int>> kClosestPoints;
36        while(!maxHeap.empty()){
37            kClosestPoints.push_back(points[maxHeap.top().second]);
38            maxHeap.pop();
39        }
40        return kClosestPoints;
41    }
42};