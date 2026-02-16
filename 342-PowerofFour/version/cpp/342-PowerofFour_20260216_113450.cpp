// Last updated: 2/16/2026, 11:34:50 AM
1class Solution {
2public:
3    bool isPowerOfFour(int n) {
4        if(n <= 0) return false;
5
6        // check power of 2
7        if((n & (n-1)) != 0) return false;
8
9        // mask to check even position
10        return (n & 0x55555555);
11    }
12};
13