class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(int i : nums)
            pq.push(i);
        for(int i = 0; i < k && pq.empty() == false; i++){
            int x = pq.top();
            pq.pop();
            if(i == k-1)
                return x;
        }
        return -1;
    }
};