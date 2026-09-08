// Last updated: 9/8/2026, 11:52:56 AM
1import java.util.*;
2
3class Solution {
4    public int[] twoSum(int[] nums, int target) {
5        Map<Integer, Integer> mp = new HashMap<>();
6        for(int i = 0; i < nums.length; i++) {
7           if(mp.containsKey(target-nums[i])) {
8               return new int[]{mp.get(target-nums[i]), i};
9           } else {
10               mp.put(nums[i], i);
11           }
12        }
13        return new int[]{-1, -1};
14    }
15}
16
17
18