// Last updated: 8/29/2025, 9:51:31 PM
class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;
        while(n > 0){
            count++;
            n = n&(n-1);
        }
        return count;
    }
};