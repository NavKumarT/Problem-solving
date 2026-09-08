// Last updated: 9/8/2026, 12:55:41 PM
1import java.util.HashMap;
2import java.util.Map;
3
4class Solution {
5
6    public int findMaxLength(int[] nums) {
7        for(int i = 0; i < nums.length; i++) {
8            if(nums[i] == 0)
9                nums[i] = -1;
10        }
11        return longestSubarray(nums, 0);
12    }
13    public int longestSubarray(int[] arr, int k) {
14        // code here
15        int max = 0, curr = 0;
16        int pre = 0;
17        Map<Integer, Integer> nn = new HashMap<>();
18        for(int i = 0 ; i < arr.length; i++) {
19            pre += arr[i];
20            if(pre == k) {
21                max = Math.max(max, i+1);
22            } else if(nn.getOrDefault(pre-k, -1) !=  -1) {
23                max = Math.max(max, i-nn.get(pre-k));
24            }
25            if(!nn.containsKey(pre)) {
26                nn.put(pre, i);
27            }
28        }
29        return max;
30    }
31}
32