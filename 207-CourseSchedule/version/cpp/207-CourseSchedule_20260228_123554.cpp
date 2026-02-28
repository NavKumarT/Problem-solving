// Last updated: 2/28/2026, 12:35:54 PM
1class Solution {
2public:
3    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
4        vector<vector<int>> adj(numCourses);
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
16        int count = q.size();
17        while(!q.empty()){
18            int course = q.front();
19            q.pop();
20            for(int n : adj[course]){
21                indegree[n]--;
22                if(indegree[n] == 0){
23                    q.push(n);
24                    count++;
25                }
26            }
27        }
28        return count == numCourses;
29    }
30};