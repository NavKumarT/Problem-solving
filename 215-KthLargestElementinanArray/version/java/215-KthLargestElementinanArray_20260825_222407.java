// Last updated: 8/25/2026, 10:24:07 PM
1import java.util.Collections;
2import java.util.PriorityQueue;
3import java.util.Queue;
4
5class Solution {
6    private Queue<Integer> pq = new PriorityQueue<>();
7    public int findKthLargest(int[] nums, int k) {
8        for(int num : nums){
9            if(pq.size() < k){
10                pq.offer(num);
11            } else if(pq.peek() < num){
12                pq.poll();
13                pq.offer(num);
14            }
15        }
16        return pq.peek();
17    }
18}