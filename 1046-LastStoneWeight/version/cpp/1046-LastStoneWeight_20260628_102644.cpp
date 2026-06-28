// Last updated: 6/28/2026, 10:26:44 AM
1class Solution {
2public:
3    int lastStoneWeight(vector<int>& stones) {
4        priority_queue<int> maxHeap;
5        for(int stone : stones){
6            maxHeap.push(stone);
7        }
8
9        while(maxHeap.size() > 1){
10            int largest = maxHeap.top();
11            maxHeap.pop();
12
13            int secondLargest = maxHeap.top();
14            maxHeap.pop();
15
16            if(abs(largest - secondLargest) > 0){
17                maxHeap.push(largest - secondLargest);
18            }
19        }
20
21        if(maxHeap.size() > 0)
22            return maxHeap.top();
23        else 
24            return 0;
25    }
26};