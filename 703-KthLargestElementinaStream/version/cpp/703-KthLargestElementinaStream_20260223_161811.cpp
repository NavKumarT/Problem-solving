// Last updated: 2/23/2026, 4:18:11 PM
1class KthLargest {
2    private:
3        priority_queue<int, vector<int>, greater<int>> pq;
4        int maxSize;
5
6public:
7    KthLargest(int k, vector<int>& nums) {
8        maxSize = k;
9        for(int num : nums){
10            if(pq.size() < k){
11                pq.push(num);
12            } else {
13                if(pq.top() < num){
14                    pq.pop();
15                    pq.push(num);
16                }
17            }
18        }
19    }
20    
21    int add(int val) {
22        if(pq.size() < maxSize){
23            pq.push(val);
24        } else {
25            if(pq.top() < val){
26                pq.pop();
27                pq.push(val);
28            }
29        }
30        return pq.top();
31    }
32};
33
34/**
35 * Your KthLargest object will be instantiated and called as such:
36 * KthLargest* obj = new KthLargest(k, nums);
37 * int param_1 = obj->add(val);
38 */