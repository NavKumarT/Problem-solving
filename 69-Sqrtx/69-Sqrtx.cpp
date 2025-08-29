// Last updated: 8/29/2025, 9:52:53 PM
class Solution {
public:
    int mySqrt(int x) {
        if(x == 0)
            return 0;
        long long unsigned int  low = 1, high = x;
        long long unsigned int  floor = 1;
        while(low <= high){
            long long unsigned int mid = low + (high-low)/2;
            long long unsigned int  square = mid * mid;
            if(square == x)
                return mid;
            else if(square > x)
                high = mid -1;
            else{
                floor = mid;
                low = mid +1;
            }
        }
        return floor;
    }
};