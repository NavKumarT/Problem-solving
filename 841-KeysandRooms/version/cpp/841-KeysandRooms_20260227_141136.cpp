// Last updated: 2/27/2026, 2:11:36 PM
1class Solution {
2public:
3    bool canVisitAllRooms(vector<vector<int>>& rooms) {
4        vector<bool> visited(rooms.size(), false);
5        visited[0] = true;
6        queue<int> q;
7        int count = 1;
8        q.push(0);
9        while(!q.empty()){
10            int room = q.front();
11            q.pop();
12            for(int neighbor : rooms[room]){
13                if(!visited[neighbor]){
14                    visited[neighbor] = true;
15                    q.push(neighbor);
16                    count++;
17                }
18            }
19        }
20        return count == rooms.size();
21    }
22};