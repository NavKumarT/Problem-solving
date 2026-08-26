// Last updated: 8/26/2026, 9:59:13 AM
1import java.util.*;
2
3class Solution {
4    public int leastInterval(char[] tasks, int n) {
5        // either the length itself or dispersed length of the max occurring element
6        int numTasks = tasks.length;
7        // Find the max occurring task(s)
8        // if k tasks maximally occur m times
9        // (n+1)*(m-1) + (k)
10        // n = 2, k = 2, m = 3
11        // A B _ A B _ A B
12        Map<Character, Integer> mp = new HashMap<>();
13        List<Character> maxChars = new ArrayList<>();
14        int maxCount = 1;
15        for(Character ch : tasks){
16            if(mp.containsKey(ch)){
17                mp.put(ch, mp.get(ch)+1);
18            } else {
19                mp.put(ch, 1);
20            }
21            if(mp.get(ch) == maxCount){
22                maxChars.add(ch);
23            } else if(mp.get(ch) > maxCount){
24                maxCount = mp.get(ch);
25                maxChars.clear();
26                maxChars.add(ch);
27            }
28        }
29        
30        int k = maxChars.size();
31        int m = maxCount;
32        return Math.max((n + 1) * (m - 1) + (k), numTasks);
33
34    }
35}