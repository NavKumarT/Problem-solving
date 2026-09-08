// Last updated: 9/8/2026, 12:58:24 PM
1import java.util.HashMap;
2import java.util.Map;
3
4class Solution {
5    public int findMaxLength(int[] nums) {
6        Map<Integer, Integer> firstSeen = new HashMap<>();
7        
8        // Prefix sum 0 exists before the array starts.
9        firstSeen.put(0, -1);
10
11        int prefix = 0;
12        int maxLength = 0;
13
14        for (int i = 0; i < nums.length; i++) {
15
16            // Treat 0 as -1 and 1 as +1.
17            prefix += nums[i] == 0 ? -1 : 1;
18
19            if (firstSeen.containsKey(prefix)) {
20                maxLength = Math.max(
21                    maxLength,
22                    i - firstSeen.get(prefix)
23                );
24            } else {
25                // Keep the earliest occurrence.
26                firstSeen.put(prefix, i);
27            }
28        }
29
30        return maxLength;
31    }
32}