// Last updated: 7/30/2026, 12:12:37 PM
1import java.util.HashMap;
2
3class Solution {
4    public int[] twoSum(int[] nums, int target) {
5        HashMap<Integer, Integer> hashmap = new HashMap<>();
6        for(int i = 0; i < nums.length; i++){
7            if(hashmap.containsKey(target-nums[i])){
8                return new int[]{i, hashmap.get(target - nums[i])};
9            }
10            hashmap.put(nums[i], i);
11        }
12        return new int[]{-1, -1};
13    }
14}