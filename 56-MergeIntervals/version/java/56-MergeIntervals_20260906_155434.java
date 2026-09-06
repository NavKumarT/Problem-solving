// Last updated: 9/6/2026, 3:54:34 PM
1class Solution {
2    public int[][] merge(int[][] intervals) {
3
4        Arrays.sort(intervals, (a, b) -> Integer.compare(a[0], b[0]));
5
6        List<int[]> result = new ArrayList<>();
7
8        int start = intervals[0][0];
9        int end = intervals[0][1];
10
11        for (int i = 1; i < intervals.length; i++) {
12
13            if (intervals[i][0] <= end) {
14                end = Math.max(end, intervals[i][1]);
15            } else {
16                result.add(new int[]{start, end});
17
18                start = intervals[i][0];
19                end = intervals[i][1];
20            }
21        }
22
23        result.add(new int[]{start, end});
24
25        return result.toArray(new int[0][]);
26    }
27}