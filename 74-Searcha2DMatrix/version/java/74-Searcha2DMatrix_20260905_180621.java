// Last updated: 9/5/2026, 6:06:21 PM
1class Solution {
2    public boolean searchMatrix(int[][] matrix, int target) {
3        int rows = matrix.length, cols = matrix[0].length;
4        int low = 0, high = rows-1;
5        int rowFound = -1;
6        while(low <= high) {
7            int mid = low + (high-low)/2;
8            if(matrix[mid][0] <= target && target <= matrix[mid][cols-1]){
9                rowFound = mid;
10                break;
11            } else if(matrix[mid][0] > target) {
12                high = mid-1;
13            } else {
14                low = mid+1;
15            }
16        }
17        if(rowFound == -1)
18            return false;
19        return bsearch(matrix[rowFound], target);
20    }
21    
22    private boolean bsearch(int[] nums, int target) {
23        int low = 0, high = nums.length-1;
24        while(low <= high) {
25            int mid = low + (high-low)/2;
26            if(nums[mid] == target) {
27                return true;
28            }
29            else if(nums[mid] > target) {
30                high = mid-1;
31            } else {
32                low = mid+1;
33            }
34            
35        }
36        return false;
37    }
38    
39}