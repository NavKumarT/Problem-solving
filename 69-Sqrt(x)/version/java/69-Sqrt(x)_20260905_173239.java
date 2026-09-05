// Last updated: 9/5/2026, 5:32:39 PM
1class Solution {
2    public int mySqrt(int x) {
3        if(x == 0)
4            return 0;
5        long low = 1, high = x, floor = 1, ceil = 1;
6        while(low <= high) {
7            long mid = low + (high-low)/2;
8            long sqr = mid * mid;
9            if(sqr == x) {
10                return (int)mid;
11            } else if(sqr > x) {
12                ceil = mid;
13                high = mid - 1;
14            } else {
15                floor = mid;
16                low = mid + 1;
17            }
18        }
19        return (int)floor;
20    }
21}