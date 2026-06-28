// Last updated: 6/28/2026, 1:08:17 PM
1class Solution {
2public:
3    vector<int> getOrder(vector<vector<int>>& tasks) {
4        // start at start time = 1
5
6        // sort the tasks based on arrival time 
7
8        // pick all elements at start time and add them to min heap
9
10        // process the top element from the heap and increment the time to starttime + time taken to process 
11
12        // pick all elements till [1 + time taken to process] from the sorted tasks array and add them to heap
13
14        // pick the top from the heap again
15
16        // continue till all the tasks are processed and return the time at which the last task is processed
17
18        int n = tasks.size();
19        for(int i = 0; i < n; i++){
20            tasks[i].push_back(i);
21        }
22
23        sort(tasks.begin(), tasks.end(), [](vector<int> &a, vector<int> &b){
24            return a[0] < b[0];
25        });
26
27        long long int currentTime = tasks[0][0];
28
29        int pointer = 0;
30
31        vector<int> processedOrder;
32
33        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap; 
34
35        while(pointer < n || minHeap.empty() == false){
36            while(pointer < n && tasks[pointer][0] <= currentTime){
37                minHeap.push({tasks[pointer][1], tasks[pointer][2]});
38                pointer++;
39            }
40
41            if(!minHeap.empty()){
42                pair<int, int> task = minHeap.top();
43                minHeap.pop();
44                currentTime += task.first;
45                processedOrder.push_back(task.second);
46            } else if (pointer < n && currentTime < tasks[pointer][0]){
47                currentTime = tasks[pointer][0];
48            }
49        }
50
51        return processedOrder; 
52    }
53};
54
55
56
57// Dry Run 
58
59// [[1,2],[2,4],[3,2],[4,1]] 
60
61
62
63
64