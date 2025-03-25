// Last updated: 3/25/2025, 11:12:58 PM
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int cols = matrix.size();
        for(int i = 0; i < cols; i++){
            for(int j = 0; j < i; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for(int i = 0; i < cols; i++){
            int start = 0, end = cols-1;
            while(start < end){
                swap(matrix[i][start], matrix[i][end]);
                start++;
                end--;
            }
        }
        return;
    }
};