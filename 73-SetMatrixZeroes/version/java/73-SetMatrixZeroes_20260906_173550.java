// Last updated: 9/6/2026, 5:35:50 PM
1import java.util.HashSet;
2import java.util.Set;
3
4class Solution {
5    public void setZeroes(int[][] matrix) {
6        Set<Integer> rows = new HashSet<>();
7        Set<Integer> cols = new HashSet<>();
8        int R = matrix.length, C = matrix[0].length;
9        for(int i = 0 ; i < R; i++) {
10            for(int j = 0; j < C; j++) {
11                if(matrix[i][j] == 0) {
12                    rows.add(i);
13                    cols.add(j);
14                    
15                }
16            }
17        }
18        for(int i = 0 ; i < R; i++) {
19            for(int j = 0; j < C; j++) {
20                if(rows.contains(i) || cols.contains(j)) {
21                    matrix[i][j] = 0;
22                }
23            }
24        }
25    }
26}