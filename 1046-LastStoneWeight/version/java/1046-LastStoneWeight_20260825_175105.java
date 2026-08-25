// Last updated: 8/25/2026, 5:51:05 PM
1import java.util.PriorityQueue;
2
3class Solution {
4    
5    private PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> b-a);
6    
7    
8    public int lastStoneWeight(int[] stones) {
9        for(int stone : stones){
10            
11            pq.offer(stone);
12        }
13        
14        while(pq.size() > 1){
15            Integer first = pq.poll();
16            Integer second = pq.poll();
17            
18            if(first == second)
19                continue;
20            else 
21                pq.offer(Math.abs(first-second));
22        }
23        if(pq.size() == 1){
24            return pq.poll();
25        }
26        return 0;
27    }
28}