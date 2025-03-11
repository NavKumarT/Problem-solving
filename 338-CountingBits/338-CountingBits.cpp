class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;
        res.push_back(0);
        for(int j = 1; j <= n; j++){
            int i = j;
            if(i == 1){
                res.push_back(1);
                continue;
            }
            int temp = 0;
            while(i > 0){
                temp++;
                i = (i & (i-1));
            }
            res.push_back(temp);
        }
        return res;
    }
};