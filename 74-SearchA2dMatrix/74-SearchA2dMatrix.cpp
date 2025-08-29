// Last updated: 8/29/2025, 9:52:50 PM
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // find the row 
        int low = 0, high = matrix.size()-1;
        int row = -1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(matrix[mid][0] == target)
                return true;
            else if(matrix[mid][0] < target){
                row = mid;
                low = mid+1;
            }            else 
                high = mid-1;
        }
        // find the element 
        if(row == -1)
            return false;
        low = 0, high = matrix[row].size()-1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(matrix[row][mid] == target)
                return true;
            else if(matrix[row][mid] > target)
                high = mid-1;
            else 
                low = mid+1;
        }
        return false;
    }
};