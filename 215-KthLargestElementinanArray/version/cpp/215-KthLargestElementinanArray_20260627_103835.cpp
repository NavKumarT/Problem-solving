// Last updated: 6/27/2026, 10:38:35 AM
1class Solution {
2public:
3    int findKthLargest(vector<int>& nums, int k) {
4        // create a min heap of size k 
5
6        priority_queue<int, vector<int>, greater<int>> minHeap;
7        for(int num : nums){
8            if(minHeap.size() < k){
9                minHeap.push(num);
10            } else {
11                if(minHeap.top() < num){
12                    minHeap.pop();
13                    minHeap.push(num);
14                }
15            }
16        }
17        return minHeap.top();
18    }
19};