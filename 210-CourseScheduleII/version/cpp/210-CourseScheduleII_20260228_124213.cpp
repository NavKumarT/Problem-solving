// Last updated: 2/28/2026, 12:42:13 PM
1class Solution {
2public:
3    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
4         vector<vector<int>> adj(numCourses);
5        vector<int> indegree(numCourses, 0);
6        for(vector<int> prerequisite : prerequisites){
7            int a = prerequisite[0], b = prerequisite[1];
8            indegree[a]++;
9            adj[b].push_back(a);
10        }
11        queue<int> q;
12        for(int i = 0; i < numCourses; i++){
13            if(indegree[i] == 0)
14                q.push(i);
15        }
16        int count = 0;
17        vector<int> order;
18        while(!q.empty()){
19            int course = q.front();
20            q.pop();
21            order.push_back(course);
22            count++;
23            for(int n : adj[course]){
24                indegree[n]--;
25                if(indegree[n] == 0){
26                    q.push(n);
27                }
28            }
29        }
30        if(numCourses != count)
31            return {};
32        return order;
33    }
34};