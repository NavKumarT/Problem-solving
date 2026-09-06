// Last updated: 9/6/2026, 10:32:04 PM
1import java.util.ArrayList;
2import java.util.Arrays;
3
4class Solution {
5    public static int[][] insert(int[][] intervals, int[] newInterval) {
6        int[][] newIntervals = new int[intervals.length+1][];
7        Arrays.sort(intervals, (a, b) -> Integer.compare(a[0], b[0]));
8        int idx = 0;
9        boolean set = false;
10        for(int[] interval : intervals) {
11            if(interval[0] > newInterval[0] && !set) {
12                newIntervals[idx] = newInterval;
13                idx++;
14                set = true;
15            }
16            newIntervals[idx] = interval;
17            idx++;
18        }
19        if(set == false)
20            newIntervals[idx] = newInterval;
21
22        int start = newIntervals[0][0], end = newIntervals[0][1];
23        ArrayList<int[]> lst = new ArrayList<>();
24        for(int i = 1; i < newIntervals.length; i++) {
25            if(newIntervals[i][0] > end) {
26                lst.add(new int[]{start, end});
27                start = newIntervals[i][0];
28                end = newIntervals[i][1];
29            } else {
30                end = Math.max(newIntervals[i][1], end);
31            }
32        }
33        lst.add(new int[]{start, end});
34        return lst.toArray(new int[0][]);
35    }
36}