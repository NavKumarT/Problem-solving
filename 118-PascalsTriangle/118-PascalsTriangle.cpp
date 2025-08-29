// Last updated: 8/29/2025, 9:52:25 PM
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i = 1; i <= numRows; i++){
            vector<int> v(i, 1);
            if(i > 2){
                vector<int> temp = ans.back();
                for(int j = 0; j < i-2; j++){
                    v[j+1] = temp[j] + temp[j+1];
                }
            }   
            ans.push_back(v);
        }
        return ans;
    }
};