// Last updated: 8/1/2026, 6:46:10 PM
1class Solution {
2    public int[] twoSum(int[] numbers, int target) {
3        int n = numbers.length;
4        int low = 0, high = n-1;
5        while(low < high){
6            int current = numbers[low] + numbers[high];
7            if(current < target)
8                low++;
9            else if(current > target)
10                high--;
11            else 
12                return new int[]{low+1, high+1};
13        }
14        return new int[]{-1, -1};
15    }
16}