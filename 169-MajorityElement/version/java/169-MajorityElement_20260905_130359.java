// Last updated: 9/5/2026, 1:03:59 PM
1class Solution {
2    public int majorityElement(int[] nums) {
3        int count = 1, element = nums[0];
4        for(int i = 1; i < nums.length; i++) {
5            if(nums[i] == element) {
6                count++;
7            } else  {
8                count--;
9                if(count == 0) {
10                count = 1;
11
12                element = nums[i];
13                }
14
15            }
16        }
17        return element;
18    }
19}