// Last updated: 9/6/2026, 5:08:48 PM
1class Solution {
2    public int[][] transpose(int[][] matrix) {
3        int R = matrix.length, C = matrix[0].length;
4        int[][] transpose = new int[C][R];
5        for(int i = 0; i < R; i++) {
6            for(int j = 0;j < C; j++) {
7                transpose[j][i] = matrix[i][j];
8            }
9        }
10        return transpose;
11    }
12}
13