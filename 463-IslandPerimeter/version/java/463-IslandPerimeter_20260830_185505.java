// Last updated: 8/30/2026, 6:55:05 PM
1import java.util.ArrayDeque;
2import java.util.Deque;
3import java.util.Queue;
4
5class Solution {
6    public int islandPerimeter(int[][] grid) {
7        int rows = grid.length, cols = grid[0].length;
8        int perimeter = 0;
9
10
11        for(int i = 0; i < rows; i++){
12            for(int j = 0; j < cols; j++){
13                if(grid[i][j] == 1){
14                    perimeter = bfs(i, j, rows, cols, grid);
15                    break;
16                }
17            }
18        }
19        
20        return perimeter;
21    }
22
23    private int bfs(int x, int y, int rows, int cols, int[][] grid) {
24        Deque<Cell> queue = new ArrayDeque<>();
25        int[] xOffset = {-1, 1, 0, 0};
26        int[] yOffset = {0, 0, 1, -1};
27        int count = 0;
28        queue.offerLast(new Cell(x, y));
29        grid[x][y] = 2;
30        while(!queue.isEmpty()){
31            Cell current = queue.pollFirst();
32            for(int i = 0 ; i < 4; i++){
33                int newX = current.x + xOffset[i];
34                int newY = current.y + yOffset[i];
35                if(newX >= 0 && newX < rows && newY >= 0 && newY < cols) {
36                    if(grid[newX][newY] == 1) {
37                        grid[newX][newY] = 2;
38                        queue.offerLast(new Cell(newX, newY));
39                    } else if(grid[newX][newY] == 0){
40                        count++;
41                    }
42                } else {
43                    count++;
44                }
45            }
46        }
47        return count;
48    }
49}
50
51
52
53class Cell {
54    int x;
55    int y;
56    Cell(int x, int y){
57        this.x = x;
58        this.y = y;
59    }
60}