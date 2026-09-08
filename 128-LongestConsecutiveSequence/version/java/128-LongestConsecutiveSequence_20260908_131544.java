// Last updated: 9/8/2026, 1:15:44 PM
1import java.util.HashSet;
2import java.util.Set;
3
4class Solution {
5    public int longestConsecutive(int[] nums) {
6        Set<Integer> s = new HashSet<>();
7        int ans =0;
8        for(int num : nums)
9            s.add(num);
10        for(Integer n :s){
11            int count = 1;
12            if(s.contains(n-1))
13                continue;
14            while(s.contains(n+count)) {
15                count++;
16            }
17            ans = Math.max(ans, count);
18        }
19        return ans;
20    }
21}