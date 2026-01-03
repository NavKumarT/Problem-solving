// Last updated: 1/3/2026, 12:24:37 PM
class Solution {
public:
    int findClosest(int x, int y, int z) {
        return abs(z-x) > abs(z-y) ? 2 : abs(z-x) == abs(z-y) ? 0 : 1; 
    }
};