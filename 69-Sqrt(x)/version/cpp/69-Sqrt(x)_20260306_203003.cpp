// Last updated: 3/6/2026, 8:30:03 PM
1class Solution {
2public:
3    int mySqrt(int x) {
4        if(x == 0)
5            return 0;
6        long long int low = 1, high = x;
7        long long int ceil = 1;
8        while(low <= high){
9            long long int mid = low + (high-low)/2;
10            long long int sqr = mid * mid;
11            if(sqr == x){
12                return mid;
13            }
14            else if(sqr < x){
15                ceil = mid;
16                low = mid+1;
17            } else {
18                high = mid-1;
19            }
20        }
21        return ceil;
22    }
23};