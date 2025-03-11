class Solution {
public:
    int countPrimes(int n) {
        if(n == 0 || n == 1)
            return 0;
        vector<bool> memo(n+1, true);
        memo[0] = false;
        memo[1] = false;
        int count = 0;
        for(long long unsigned int i = 2; i < n; i++){
            if(memo[i]){
                for(long long unsigned int j = i*i; j< n; j+=i)
                   {if(memo[j])
                    count++; 
                    memo[j] = false;
                   }
            }
        }
        return n-count-2;
    }
};