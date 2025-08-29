// Last updated: 8/29/2025, 9:50:08 PM
class KthLargest {
private: 
    int size = 0;
    priority_queue<int, vector<int>, greater<>> pq;  // using a min heap 
    int kk = 0;
public:
    KthLargest(int k, vector<int>& nums) {
        kk = k;
        for(int num : nums){
            if(pq.size() < k)
                pq.push(num);
            else if(pq.top() < num){
                pq.pop();
                pq.push(num);
            }
        }
    }
    
    int add(int val) {
        if(pq.size() < kk)
            pq.push(val);
        else if(pq.top() < val){
            pq.pop();
            pq.push(val);}
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */