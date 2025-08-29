// Last updated: 8/29/2025, 9:50:57 PM
class Solution {
public:
    bool isPerfectSquare(int num) {
        long long unsigned int low = 1, high = num;
        while(low <= high){
            long long unsigned int mid = low + (high-low)/2;
            long long unsigned int sq = mid * mid;
            if(sq == num)
                return true;
            else if(sq > num)
                high = mid - 1;
            else 
                low = mid + 1;
        }
        return false;
    }
};