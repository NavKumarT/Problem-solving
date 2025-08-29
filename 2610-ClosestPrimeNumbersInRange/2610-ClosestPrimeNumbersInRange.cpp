// Last updated: 8/29/2025, 9:48:09 PM
class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool> memo(right+1, true);
        memo[0] = false;
        memo[1] = false;
        for(long long unsigned int i = 2; i <= right; i++){
            if(memo[i]){
                for(long long unsigned int j = i*i; j <= right; j+=i){
                    memo[j] = false;
                }
            }
        }
        vector<int> res;
        for(int i = left; i<= right; i++)
            if(memo[i])
                res.push_back(i);
        int minimum = INT_MAX;
        int first = -1, second = -1;
        for(int k = 1; k < res.size(); k++){
            if(res[k]-res[k-1] < minimum){
                first = res[k-1];
                second = res[k];
                minimum = res[k]-res[k-1];
            }
        }
        return {first, second};
    }
};