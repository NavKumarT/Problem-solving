// Last updated: 9/5/2026, 11:58:32 AM
1class Solution {
2    public int[] replaceElements(int[] arr) {
3        int max = -1;
4        for(int i = arr.length-1; i >= 0; i--){
5            if(max == -1) {
6                max = arr[i];
7                arr[i] = -1;
8            } else {
9                int temp = arr[i];
10                arr[i] = max;
11                max = Math.max(temp, max);
12            }
13        }
14        return arr;
15    }
16}