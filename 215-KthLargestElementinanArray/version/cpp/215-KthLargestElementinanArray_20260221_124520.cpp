// Last updated: 2/21/2026, 12:45:20 PM
1class Solution {
2public:
3    int findKthLargest(vector<int>& nums, int k) {
4        priority_queue<int, vector<int>, greater<>> pq;
5        for(int num : nums){
6            if(pq.size() >= k){
7                if(pq.top() < num){
8                    pq.pop();
9                    pq.push(num);
10                }
11            } else {
12                pq.push(num);
13            }
14        }
15        return pq.top();
16    }
17};