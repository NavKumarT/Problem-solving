// Last updated: 7/30/2026, 10:09:36 AM
1class Solution {
2    public boolean containsDuplicate(int[] nums) {
3        HashSet<Integer> hs = new HashSet<>();
4        for(int num : nums){
5            if(hs.contains(num))
6                return true;
7            hs.add(num);
8        }
9        return false;
10    }
11}