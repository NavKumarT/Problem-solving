// Last updated: 8/29/2025, 9:51:23 PM
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // using topological sort
        vector<int> inDegree(numCourses, 0);
        vector<vector<int>> adjacencyMatrix(numCourses);
        for(vector<int> vec : prerequisites){
            inDegree[vec[0]]++;
            adjacencyMatrix[vec[1]].push_back(vec[0]);
        }
        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }

        vector<int> res;
        while(q.empty() == false){
            int x = q.front(); q.pop();
            res.push_back(x);
            for(int y : adjacencyMatrix[x]){
                inDegree[y]--;
                if(inDegree[y] == 0)
                    q.push(y);
            }
        }

        for(int x : inDegree)
            if(x != 0)
                return {};
        return res;
    }
};