// Last updated: 9/6/2026, 4:30:52 PM
1
2import java.util.Arrays;
3
4
5class Solution {
6    public int eraseOverlapIntervals(int[][] intervals) {
7        Arrays.sort(intervals, (a, b) -> Integer.compare(a[1], b[1]));
8        int end = intervals[0][1];
9        int count = 0;
10        for (int i = 1; i < intervals.length; i++) {
11            if(intervals[i][0] < end) {
12                count++;
13                continue;
14            } else {
15                end = intervals[i][1];
16            }
17        }
18        return count;
19    }
20}
21