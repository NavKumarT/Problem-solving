// Last updated: 2/13/2026, 11:06:01 PM
1class Solution {
2public:
3    vector<int> spiralOrder(vector<vector<int>>& matrix) {
4        int rows = matrix.size(), cols= matrix[0].size();
5        int top = 0, left = 0, right = cols-1, bottom = rows-1;
6        vector<int> n;
7        while(top <= bottom && left <= right){
8            for(int i = left; i <= right; i++){
9                n.push_back(matrix[top][i]);
10            }
11            top++;
12            for(int i = top; i <= bottom; i++){
13                n.push_back(matrix[i][right]);
14            }
15            right--;
16            if(top <= bottom){
17                for(int i = right; i >= left; i--){
18                    n.push_back(matrix[bottom][i]);
19                }
20                bottom--;
21            }
22            if(left <= right){
23            for(int i = bottom; i  >= top; i--){
24                n.push_back(matrix[i][left]);
25            }
26            left++;
27            }
28        }
29        return n;
30    }
31};