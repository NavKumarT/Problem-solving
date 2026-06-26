// Last updated: 6/26/2026, 9:51:42 AM
1class KthLargest {
2    private: 
3        priority_queue<int, vector<int>, greater<int>> minHeap;
4        int maxSize;
5    public:
6        KthLargest(int k, vector<int>& nums) {
7            maxSize = k;
8            for(int num : nums){
9                if(minHeap.size() < maxSize){
10                    minHeap.push(num);
11                } else {
12                    if(minHeap.top() < num){
13                        minHeap.pop();
14                        minHeap.push(num);
15                    }
16                }
17            }
18        }
19        
20        int add(int num) {
21            if(minHeap.size() < maxSize){
22                minHeap.push(num);
23            } else {
24                if(minHeap.top() < num){
25                    minHeap.pop();
26                    minHeap.push(num);
27                }
28            }
29            return minHeap.top();
30        }
31};
32
33// make a min heap of k elements 
34// add to the min heap only if the new element is larger than the root of the heap 
35// if it is smaller than the root, do not add to the heap as the kth largest wont change 
36// at any point, the root of the heap is the kth largest element 
37
38/**
39 * Your KthLargest object will be instantiated and called as such:
40 * KthLargest* obj = new KthLargest(k, nums);
41 * int param_1 = obj->add(val);
42 */