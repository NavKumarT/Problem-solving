// Last updated: 9/8/2026, 4:35:39 PM
1class Solution {
2    public int[] singleNumber(int[] nums) {
3        int xor = 0, res1 = 0, res2 = 0;
4        for(int num : nums){
5            xor = xor ^ num;
6        }
7        long sb  = xor & (~(xor-1));
8        for(int num : nums){
9            if((num & sb) != 0){
10                res1 = res1 ^ num;
11            } else {
12                res2 = res2 ^ num;
13            }
14        }
15        return new int[]{res1, res2};
16    }
17}