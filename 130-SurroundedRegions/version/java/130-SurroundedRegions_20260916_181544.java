// Last updated: 9/16/2026, 6:15:44 PM
1import java.sql.Array;
2import java.util.ArrayDeque;
3import java.util.Queue;
4
5class Solution {
6    public void solve(char[][] board) {
7        int rows = board.length, cols = board[0].length;
8        for(int i = 0; i < rows; i++) {
9            for(int j = 0; j < cols; j++) {
10                if((i == 0 || j == 0 || i == rows-1 || j == cols-1) && board[i][j] == 'O') {
11                    bfs(board, i, j);
12                }
13            }
14        }
15        for(int i = 0; i < rows; i++) {
16            for(int j = 0; j < cols; j++) {
17                if(board[i][j] == 'O') {
18                    board[i][j] = 'X';
19                }
20            }
21        }
22        for(int i = 0; i < rows; i++) {
23            for(int j = 0; j < cols; j++) {
24                if(board[i][j] == 'Y') {
25                    board[i][j] = 'O';
26                }
27            }
28        }
29    }
30    
31    void bfs(char[][] board, int x, int y) {
32        int rows = board.length, cols = board[0].length;
33        Queue<int[]> queue = new ArrayDeque<>();
34        board[x][y] = 'Y';
35        queue.offer(new int[]{x, y});
36        int[] dx = new int[]{0, 0, 1, -1};
37        int[] dy = new int[]{1, -1, 0, 0};
38        while(!queue.isEmpty()) {
39            int[] point = queue.poll();
40            // traverse the 4 valid directions and add to queue if 'O'
41            for(int i =0 ; i <4; i++) {
42                int newX = point[0] + dx[i];
43                int newY = point[1] + dy[i];
44                if(newX >= 0 && newX < rows && newY >= 0 && newY < cols) {
45                    if(board[newX][newY] == 'O'){
46                        board[newX][newY] = 'Y';
47                        queue.offer(new int[]{newX, newY});
48                    }
49                }
50            }
51        }
52    }
53}