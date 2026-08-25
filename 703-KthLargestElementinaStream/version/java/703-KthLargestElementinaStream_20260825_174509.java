// Last updated: 8/25/2026, 5:45:09 PM
1import java.util.PriorityQueue;
2
3class KthLargest {
4
5    private PriorityQueue<Integer> pq;
6    private Integer size;
7    public KthLargest(int k, int[] nums) {
8        this.size = k;
9        this.pq = new PriorityQueue<>();
10        for(int num : nums){
11            add(num);
12        }
13    }
14
15    public int add(int val) {
16        if(pq.size() < size){
17            pq.offer(val);
18        } else {
19            if(pq.peek() < val){
20                pq.poll();
21                pq.offer(val);
22            }
23        }
24        return pq.peek();
25    }
26}
27
28/**
29 * Your KthLargest object will be instantiated and called as such:
30 * KthLargest obj = new KthLargest(k, nums);
31 * int param_1 = obj.add(val);
32 */