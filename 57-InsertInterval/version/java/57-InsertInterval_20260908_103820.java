// Last updated: 9/8/2026, 10:38:20 AM
1
2import java.util.ArrayList;
3
4class Solution {
5    public int[][] insert(int[][] intervals, int[] newInterval) {
6
7        ArrayList<int[]> result = new ArrayList<>();
8        int i = 0;
9
10        // 1. Add intervals completely before newInterval
11        while (i < intervals.length && intervals[i][1] < newInterval[0]) {
12            result.add(intervals[i]);
13            i++;
14        }
15
16        // 2. Merge all overlapping intervals
17        while (i < intervals.length && intervals[i][0] <= newInterval[1]) {
18            newInterval[0] = Math.min(newInterval[0], intervals[i][0]);
19            newInterval[1] = Math.max(newInterval[1], intervals[i][1]);
20            i++;
21        }
22
23        // 3. Add the merged interval
24        result.add(newInterval);
25
26        // 4. Add intervals completely after newInterval
27        while (i < intervals.length) {
28            result.add(intervals[i]);
29            i++;
30        }
31
32        return result.toArray(new int[result.size()][]);
33    }
34}