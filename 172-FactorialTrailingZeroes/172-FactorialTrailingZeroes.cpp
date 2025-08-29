// Last updated: 8/29/2025, 9:51:34 PM
class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        for(int i = 5; i <= n; i*=5)
            res += n/i;
        return res;
    }
};