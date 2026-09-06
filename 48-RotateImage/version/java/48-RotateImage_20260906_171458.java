// Last updated: 9/6/2026, 5:14:58 PM
1class Solution {
2    public void rotate(int[][] matrix) {
3        int R = matrix.length, C = R;
4        for(int i = 0; i < R; i++) {
5            for(int j = i+1; j < C; j++){
6                int temp = matrix[i][j];
7                matrix[i][j] = matrix[j][i];
8                matrix[j][i] = temp;
9            }
10        }
11        for(int i = 0 ; i < R; i++) {
12            int low = 0, high = C-1;
13            while(low < high) {
14                int temp = matrix[i][low];
15                matrix[i][low] = matrix[i][high];
16                matrix[i][high] = temp;
17                low++;
18                high--;
19            }
20        }
21    }
22}