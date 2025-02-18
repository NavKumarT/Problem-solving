class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> currentRes;
        int i = 0;
        func(ans, currentRes, i, k, n);
        return ans;
    }

    void func(vector<vector<int>> &res, vector<int> &currentRes, int i, int k, int n){
        if(currentRes.size() == k){
            res.push_back(currentRes);
            return;
        }
        if(i >= n)
            return;
        currentRes.push_back(i+1);
        func(res, currentRes, i+1, k, n);
        currentRes.pop_back();
        func(res, currentRes, i+1, k, n);
    }
};