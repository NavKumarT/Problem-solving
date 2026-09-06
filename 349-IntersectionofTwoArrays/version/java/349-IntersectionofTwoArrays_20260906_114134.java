// Last updated: 9/6/2026, 11:41:34 AM
1import java.util.*;
2
3class Solution {
4    public static int[] intersection(int[] nums1, int[] nums2) {
5        Set<Integer> s = new HashSet<>();
6        for(int num : nums1)
7            s.add(num);
8        List<Integer> lst = new ArrayList<>();
9        for(int num : nums2) {
10            if(s.contains(num)) {
11                lst.add(num);
12                s.remove(num);
13            }
14        }
15        return lst.stream().mapToInt(Integer::intValue).toArray();
16    }
17}