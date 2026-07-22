// Last updated: 7/22/2026, 9:49:17 PM
// Java Solution
1class Solution {
2    public int majorityElement(int[] nums) {
3        int count = 1;
4        int element  = nums[0];
5        for(int i = 1; i < nums.length; i++){
6            if(nums[i] == element){
7                count++;
8            } else {
9                count--;
10                if(count == 0){
11                    count = 1;
12                    element = nums[i];
13                }
14            }
15        }
16        return element;
17    }
18
19}