class KthLargest {
    private: 
    priority_queue<int, vector<int>, greater<>> minHeap;
    int k;
public:
    KthLargest(int kk, vector<int>& nums) {
        k = kk;
        for (int num : nums) {
        minHeap.push(num);
        
        // Ensure the heap does not exceed size k
        if (minHeap.size() > k) {
            minHeap.pop();  // Remove the smallest element to maintain heap size k
        }
    }
    }
    
    int add(int num) {
         minHeap.push(num);
        
        // Ensure the heap does not exceed size k
        if (minHeap.size() > k) {
            minHeap.pop();  // Remove the smallest element to maintain heap size k
        }
        return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */