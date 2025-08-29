// Last updated: 8/29/2025, 9:50:50 PM
class Solution {
public:
    int arrangeCoins(int n) {
        long long unsigned int ans = 1;
        long long unsigned int low = 1, high = n, floor = low;
        while(low <= high){
            long long unsigned int mid = low + (high-low)/2;
            ans = (mid)*(mid+1)/2;
            if(ans == n)
                return mid;
            else if(ans > n)
                high = mid-1;
            else {
                floor = mid;
                low = mid+1;
            }
        }
        return floor;
    }
};