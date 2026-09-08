// Last updated: 9/8/2026, 11:20:04 AM
1import java.util.ArrayList;
2import java.util.List;
3
4class Solution {
5    public static List<Integer> spiralOrder(int[][] matrix) {
6        List<Integer> traversal = new ArrayList<>();
7        int rows = matrix.length, cols = matrix[0].length;
8        int left = 0, right = cols-1, top = 0, bottom = rows-1;
9        while(left <= right && top <= bottom) {
10            // top rows
11            for(int i = left; i <= right; i++) {
12                traversal.add(matrix[top][i]);
13            }
14            // right column
15            if(bottom-top > 1) {
16                for(int i = top+1; i < bottom; i++) {
17                    traversal.add(matrix[i][right]);
18                }
19            }
20
21            // bottom row in reverse
22            if(bottom-top > 0) {
23                for(int i = right; i >= left; i--) {
24                    traversal.add(matrix[bottom][i]);
25                }
26            }
27
28            // left column in reverse
29            if(bottom-top > 1 && right-left > 0) {
30                for(int i = bottom-1; i > top; i--) {
31                    traversal.add(matrix[i][left]);
32                }
33            }
34           left++;
35            right--;
36            top++;
37            bottom--;
38        }
39        return traversal;
40    }
41}