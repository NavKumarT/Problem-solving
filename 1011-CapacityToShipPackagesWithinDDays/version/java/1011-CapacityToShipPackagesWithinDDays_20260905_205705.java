// Last updated: 9/5/2026, 8:57:05 PM
1import java.util.Arrays;
2
3class Solution {
4    public static int shipWithinDays(int[] weights, int days) {
5//        Arrays.sort(weights);
6        int low = weights[0], high = weights[weights.length-1];
7        int sum = 0;
8        for(int weight : weights) {
9            sum += weight;
10            low = Math.max(low, weight);
11        }
12        high = sum;
13        int floor = -1;
14        while(low <= high) {
15            int mid = low + (high-low)/2;
16            int curr = calculate(weights, mid);
17            if(curr <= days) {
18                floor = mid;
19                high = mid-1;
20            } else {
21                low = mid+1;
22            }
23        }
24        return floor;
25    }
26
27    private static int calculate(int[] arr, int capacity) {
28        int curr = 0, count = 0;
29        for(int weight : arr) {
30            if(curr + weight <= capacity) {
31                curr += weight;
32            } else {
33                curr = weight;
34                count++;
35            }
36        }
37        count++;
38        return count;
39    }
40}