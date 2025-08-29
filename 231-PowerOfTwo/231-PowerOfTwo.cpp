// Last updated: 8/29/2025, 9:51:15 PM
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n == 1)
            return true;
        if(n <= 0)
            return false;
        return (n & (n-1)) > 0 ? false : true;
    }
};