// Last updated: 9/5/2026, 12:13:37 PM
1import java.util.*;
2
3class Solution {
4    public int[] frequencySort(int[] nums) {
5        Map<Integer, Integer> mp = new HashMap<>();
6        Queue<int[]> minHeap = new PriorityQueue<>((a, b) -> {
7            if(a[1] != b[1]) {
8                return Integer.compare(a[1], b[1]);
9            } else {
10                return Integer.compare(b[0], a[0]);
11            }
12        });
13        for(int num : nums){
14            mp.put(num, mp.getOrDefault(num,0) + 1);
15        }
16        for(Map.Entry<Integer, Integer> e : mp.entrySet()) {
17            minHeap.offer(new int[]{e.getKey(), e.getValue()});
18        }
19        int[] lst = new int[nums.length];
20        int idx = 0;
21        while(idx < nums.length){
22            int[] top = minHeap.poll();
23            assert top != null;
24            int k = top[1];
25            int n = top[0];
26            while(k > 0){
27                lst[idx] = n;
28                idx++;
29                k--;
30            }
31        }
32        return lst;
33    }
34}