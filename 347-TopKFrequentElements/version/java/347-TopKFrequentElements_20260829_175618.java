// Last updated: 8/29/2026, 5:56:18 PM
1import java.util.HashMap;
2import java.util.Map;
3import java.util.PriorityQueue;
4import java.util.Queue;
5
6class Solution {
7    public int[] topKFrequent(int[] nums, int k) {
8        Map<Integer, Integer> mp = new HashMap<>();
9        for(int num : nums){
10            mp.put(num, mp.getOrDefault(num, 0)+1);
11        }
12
13        Queue<FreqElement> minHeap = new PriorityQueue<>((a, b) -> a.freq - b.freq);
14        mp.forEach((key, value) ->{
15            if(minHeap.size() < k){
16                minHeap.offer(new FreqElement(key, value));
17            } else {
18                if(minHeap.peek().freq < value){
19                    minHeap.poll();
20                    minHeap.offer(new FreqElement(key, value));
21                }
22            }
23        });
24        int[] ans = new int[k];
25        int idx = 0;
26        while(!minHeap.isEmpty()) {
27            ans[idx] = minHeap.poll().value;
28            idx++;
29        }
30        return ans;
31    }
32}
33
34class FreqElement {
35    int value;
36    int freq;
37    FreqElement(int value, int freq){
38        this.value = value;
39        this.freq = freq;
40    }
41}