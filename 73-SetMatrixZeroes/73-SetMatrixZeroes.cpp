// Last updated: 03/06/2025, 14:16:08
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> s_rows, s_cols;
        int rows = matrix.size(), cols = matrix[0].size();
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(matrix[i][j] == 0){
                    s_rows.insert(i);
                    s_cols.insert(j);
                }
            }
        }

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(s_rows.find(i) != s_rows.end() || s_cols.find(j) != s_cols.end()){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};