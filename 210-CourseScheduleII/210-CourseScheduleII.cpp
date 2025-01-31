class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        for(int i = 0; i < prerequisites.size(); i++){
            inDegree[prerequisites[i][0]]++;
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        queue<int> q;
        int count = 0;
        vector<int> coursesOrder;
        for(int i = 0; i < numCourses; i++){
            if(inDegree[i] == 0)
                q.push(i);
        }
        while(q.empty() == false){
            int u = q.front();
            q.pop();
            coursesOrder.push_back(u);
            count++;
            for(int x : adj[u]){
                inDegree[x] -= 1;
                if(inDegree[x] == 0)
                    q.push(x);
            }
        }
        if(count == numCourses)
            return coursesOrder;
        return {};
    }
};