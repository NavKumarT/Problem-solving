// Last updated: 6/27/2026, 12:40:07 PM
1class Solution {
2public:
3    int leastInterval(vector<char>& tasks, int n) {
4        
5        // lets write a heap based approach to practice 
6
7        // making a max heap {freq, char}
8
9        // get the n+1 max elements out, decrement them and keep aside 
10
11        // push them back to the heap after n+1 iterations 
12
13        // return the total steps to make the heap.size() == 0
14
15        priority_queue<pair<int, char>> maxHeap;
16        unordered_map<char, int> hashMap;
17
18        for(char task : tasks){
19            hashMap[task]++;
20        }
21
22        for(auto it : hashMap){
23            maxHeap.push({it.second, it.first});
24        }
25
26        int count = 0;
27        while(maxHeap.empty() == false){
28            vector<pair<int, char>> arr;
29            int i;
30            for( i = 0 ; i <= n; i++){
31                if(maxHeap.empty())
32                    break;
33                pair<int, char> task = maxHeap.top();
34                maxHeap.pop();
35                if(task.first-1 > 0)
36                    arr.push_back({task.first-1, task.second});
37                count++;
38            }
39            if(arr.size() == 0 && maxHeap.size() == 0)
40                break;
41            count+= n-i+1;
42            for(pair<int, char> task : arr)
43                maxHeap.push(task);
44        }
45        return count;
46    }
47};