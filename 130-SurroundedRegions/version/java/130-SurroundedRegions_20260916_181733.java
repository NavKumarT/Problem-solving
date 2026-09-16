// Last updated: 9/16/2026, 6:17:33 PM
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
17 if (board[i][j] == 'O')
18    board[i][j] = 'X';
19else if (board[i][j] == 'Y')
20    board[i][j] = 'O';
21            }
22        }
23    }
24    
25    void bfs(char[][] board, int x, int y) {
26        int rows = board.length, cols = board[0].length;
27        Queue<int[]> queue = new ArrayDeque<>();
28        board[x][y] = 'Y';
29        queue.offer(new int[]{x, y});
30        int[] dx = new int[]{0, 0, 1, -1};
31        int[] dy = new int[]{1, -1, 0, 0};
32        while(!queue.isEmpty()) {
33            int[] point = queue.poll();
34            // traverse the 4 valid directions and add to queue if 'O'
35            for(int i =0 ; i <4; i++) {
36                int newX = point[0] + dx[i];
37                int newY = point[1] + dy[i];
38                if(newX >= 0 && newX < rows && newY >= 0 && newY < cols) {
39                    if(board[newX][newY] == 'O'){
40                        board[newX][newY] = 'Y';
41                        queue.offer(new int[]{newX, newY});
42                    }
43                }
44            }
45        }
46    }
47}