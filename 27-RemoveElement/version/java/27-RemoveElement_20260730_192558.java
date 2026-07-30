// Last updated: 7/30/2026, 7:25:58 PM
1class Solution {
2    public int removeElement(int[] nums, int val) {
3        int left = 0, right = nums.length-1;
4        while(left <= right){
5            while(left <= right && nums[left] != val)
6                left++;
7            while(left <= right && nums[right] == val)
8                right--;
9            if(left < right){
10                int temp = nums[left];
11                nums[left] = nums[right];
12                nums[right] = temp;
13                left++;
14                right--;
15            }
16        }
17        return right+1;
18    }
19}