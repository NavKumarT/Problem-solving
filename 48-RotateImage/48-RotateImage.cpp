// Last updated: 03/06/2025, 14:05:45
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        swapRowsAndColumns(matrix);
        reverseRows(matrix);
    }

    void swapRowsAndColumns(vector<vector<int>> &matrix){
        int rows = matrix.size(); // number of rows 
        int cols = matrix[0].size(); // number of cols 
        for(int i = 0; i < rows; i++){
            for(int j = i; j < cols; j++)
                swap(matrix[i][j], matrix[j][i]);
        }
    }

    void reverseRows(vector<vector<int>> &matrix){
        int rows = matrix.size(); // number of rows 
        int cols = matrix[0].size(); // number of cols 
        for(int i = 0; i < rows; i++){
            int low = 0, high = cols-1;
            while(low < high){
                int temp = matrix[i][low];
                matrix[i][low] = matrix[i][high];
                matrix[i][high] = temp;
                low++;
                high--;
            }
        }
    }
};