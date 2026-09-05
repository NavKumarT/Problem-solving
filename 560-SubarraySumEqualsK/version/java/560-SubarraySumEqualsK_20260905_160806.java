// Last updated: 9/5/2026, 4:08:06 PM
1import java.util.HashMap;
2import java.util.Map;
3
4class Solution {
5    public int subarraySum(int[] nums, int k) {
6        Map<Integer, Integer> mp = new HashMap<>();
7        int prefixSum = 0;
8        int count = 0;
9        for(int i = 0; i < nums.length; i++) {
10            prefixSum += nums[i];
11            if(prefixSum == k)
12                count++;
13            if(mp.getOrDefault(prefixSum-k, 0) != 0){
14                count += mp.get(prefixSum-k);
15            }
16            mp.put(prefixSum, mp.getOrDefault(prefixSum,0) + 1);
17        }
18        return count;
19    }
20}