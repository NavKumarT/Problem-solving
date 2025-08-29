// Last updated: 8/29/2025, 9:47:50 PM
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int repeating, didNotOccur;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[(abs(grid[i][j])-1)/n][(abs(grid[i][j])-1)%n]< 0){
                    repeating = abs(grid[i][j]);
                } else {
                    grid[(abs(grid[i][j])-1)/n][(abs(grid[i][j])-1)%n] = grid[(abs(grid[i][j])-1)/n][(abs(grid[i][j])-1)%n] * -1;
                }
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] > 0){
                    didNotOccur = i*n + j + 1;
                    break;
                }
            }
        }
        return {repeating, didNotOccur};
    }
};