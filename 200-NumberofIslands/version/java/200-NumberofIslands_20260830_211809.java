// Last updated: 8/30/2026, 9:18:09 PM
1import java.sql.Array;
2import java.util.ArrayDeque;
3import java.util.Deque;
4
5class Solution {
6    public int numIslands(char[][] grid) {
7        int numIslandsCount = 0;
8        int rows = grid.length, cols = grid[0].length;
9        for(int i = 0; i < rows; i++) {
10            for(int j = 0; j < cols; j++) {
11                if(grid[i][j] == '1'){
12                    numIslandsCount++;
13                    bfs(i, j, grid);
14                }
15            }
16        }
17        return numIslandsCount;
18    }
19
20    private void bfs(int x, int y, char[][] grid) {
21        int rows = grid.length, cols = grid[0].length;
22        Deque<int[]> queue = new ArrayDeque<>();
23        queue.offerLast(new int[]{x, y});
24        grid[x][y] = '2';
25        int[] dx = {0, 0, -1, 1};
26        int[] dy = {-1, 1, 0, 0};
27        while(!queue.isEmpty()){
28            int[] coordinates = queue.pollFirst();
29            for(int i = 0; i < 4; i++){
30                int newX = coordinates[0] + dx[i];
31                int newY = coordinates[1] + dy[i];
32                if(newX >= 0 && newX < rows && newY >= 0 && newY < cols){
33                    if(grid[newX][newY] == '1') {
34                        grid[newX][newY] = '2';
35                        queue.offerLast(new int[]{newX, newY});
36                    }
37                }
38            }
39        }
40    }
41}