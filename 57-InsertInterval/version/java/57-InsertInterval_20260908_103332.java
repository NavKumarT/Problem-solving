// Last updated: 9/8/2026, 10:33:32 AM
1import java.lang.reflect.Array;
2import java.util.ArrayList;
3import java.util.Arrays;
4
5class Solution {
6    public static int[][] insert(int[][] intervals, int[] newInterval) {
7        int i = 0;
8        ArrayList<int[]> arr = new ArrayList<>();
9        int currStart, currEnd;
10        boolean added = false;
11        while(i < intervals.length){
12            currStart = intervals[i][0];
13            currEnd = intervals[i][1];
14            // base case when there is no overlap
15            if(newInterval[0] > currEnd) {
16                arr.add(new int[]{currStart, currEnd});
17                i++;
18            } else if(currStart > newInterval[1]) {
19                if(!added) {
20                    arr.add(newInterval);
21                    added = true;
22                }
23                arr.add(new int[]{currStart, currEnd});
24                i++;
25            } else {
26                added = true;
27                currStart = Math.min(currStart, newInterval[0]);
28                currEnd = Math.max(currEnd, newInterval[1]);
29                i++;
30                while(i < intervals.length && currEnd >= intervals[i][0]) {
31                    currEnd = Math.max(currEnd, intervals[i][1]);
32                    i++;
33                }
34                arr.add(new int[]{currStart, currEnd});
35            }
36        }
37        if(!added) {
38            arr.add(newInterval);
39            added = true;
40        }
41        return arr.toArray(new int[0][]);
42    }
43}