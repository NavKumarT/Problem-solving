// Last updated: 8/29/2025, 9:48:06 PM
class Solution {
public:
    long long coloredCells(int n) { return 1 + (long long)n * (n - 1) * 2; }
};