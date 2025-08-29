// Last updated: 8/29/2025, 9:49:07 PM
class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        // using topological sort
        vector<int> inDegree(numCourses, 0);
        vector<vector<int>> adjacencyMatrix(numCourses);
        for(vector<int> vec : prerequisites){
            inDegree[vec[1]]++;
            adjacencyMatrix[vec[0]].push_back(vec[1]);
        }
        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }
        vector<unordered_set<int>> pre(numCourses);
        for(int k = 0; k < numCourses; k++){
            pre[k].insert(k);
        }
        while(q.empty() == false){
            int size = q.size();
            for(int k = 0; k < size; k++){
                int x = q.front(); q.pop();
                for(int y : adjacencyMatrix[x]){
                    inDegree[y]--;
                    pre[y].insert(pre[x].begin(), pre[x].end());
                    if(inDegree[y] == 0){
                        q.push(y);
                    }
                }
            }
        }
        vector<bool> res;
        for(vector<int> vec : queries){
            if(pre[vec[1]].find(vec[0]) != pre[vec[1]].end())
                res.push_back(true);
            else 
                res.push_back(false);
        }
        return res;
    }
};