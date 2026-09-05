// Last updated: 9/5/2026, 1:19:32 PM
1import java.util.ArrayList;
2import java.util.List;
3
4class Solution {
5    public List<Integer> majorityElement(int[] nums) {
6        int first = -1, second = -1, count1 = 0, count2 = 0;
7        for(int num : nums) {
8            if(num == first) {
9                count1++;
10            } else if(num == second) {
11                count2++;
12            } else if(count1 == 0) {
13                count1 = 1;
14                first = num;
15            } else if(count2 == 0) {
16                count2 = 1;
17                second = num;
18            }else {
19                count1--;
20                count2--;
21            }
22        }
23        count1 = 0;
24    count2 = 0;
25        for(int num : nums){
26            if(num == first)
27                    count1++;
28            else if(num == second)
29                count2++;
30        }
31        List<Integer> lst = new ArrayList<>();
32        if(count1 > nums.length/3)
33            lst.add(first);
34        if(count2 > nums.length/3)
35            lst.add(second);
36        return lst;
37    }
38}