// Last updated: 2/17/2026, 8:02:59 PM
1class Solution {
2public:
3    void reverseString(vector<char>& s) {
4        int low = 0, high = s.size()-1;
5        while(low <  high ){
6            swap(s[high--], s[low++]);
7        }
8        return;
9    }
10};