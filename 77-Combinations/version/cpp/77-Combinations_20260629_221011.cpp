// Last updated: 6/29/2026, 10:10:11 PM
1class Solution {
2public:
3    vector<vector<int>> combine(int n, int k) {
4        vector<vector<int>> combinations;
5        vector<int> temp;
6        int i = 1;
7        backtracking(combinations, temp, i, n, k);
8        return combinations;
9    }
10
11    void backtracking(vector<vector<int>> &combinations, vector<int> &temp, int i, int n, int k){
12        if(k == temp.size()){
13            combinations.push_back(temp);
14            return;
15        }
16        if(i > n){
17            return;
18        }
19        temp.push_back(i);
20        backtracking(combinations, temp, i+1, n, k);
21        temp.pop_back();
22        backtracking(combinations, temp, i+1, n, k);
23    }
24};