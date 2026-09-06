// Last updated: 9/6/2026, 3:43:36 PM
1import java.sql.Array;
2import java.util.ArrayList;
3import java.util.Arrays;
4import java.util.List;
5
6class Solution {
7    public static int[][] merge(int[][] intervals) {
8        // find the max, make an array of size max + 2
9        int max = intervals[0][0];
10        for(int[] interval : intervals){
11            max = Math.max(max, interval[1]);
12        }
13        int[] diffStart = new int[max+2];
14        int[] diffEnd = new int[max+2];
15
16        for(int[] interval : intervals) {
17            diffStart[interval[0]]++;
18            diffEnd[interval[1]]++;
19        }
20
21        int curr = 0;
22        int currStart = -1, currEnd = -1;
23        List<int[]> lst = new ArrayList<>();
24        for(int i = 0; i < diffStart.length; i++){
25            curr += diffStart[i];
26            if(curr > 0 && currStart == -1)
27                currStart = i;
28            curr -= diffEnd[i];
29            if(curr == 0 && currStart != -1){
30                currEnd = i;
31                lst.add(new int[]{currStart, currEnd});
32                currStart = -1;
33                currEnd = -1;
34            }
35        }
36        return lst.toArray(new int[0][]);
37    }
38}
39
40