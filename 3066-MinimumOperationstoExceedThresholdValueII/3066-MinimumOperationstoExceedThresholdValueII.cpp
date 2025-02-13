class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<>> pq;
        for(int x : nums){
            pq.push(x);
        }
        int count = 0;
        while(pq.empty() == false && pq.top() < k){
            long long a = pq.top();
            pq.pop();
            long long b = pq.top();
            pq.pop();
            pq.push(min(a, b) * 2 + max(a, b));
            cout << min(a, b) * 2 + max(a, b) << " ";
            count++;
        }
        return count;
    }
};