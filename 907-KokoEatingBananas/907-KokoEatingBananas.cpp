// Last updated: 8/29/2025, 9:49:57 PM
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());
        unsigned long long int low = 1, high = piles[piles.size()-1];
        int ans = INT_MAX;
        while(low <= high){
            unsigned long long int  mid = low + (high-low)/2;
            unsigned long long int count = 0;
            for(int i : piles)
                if(i % mid == 0)
                    count += i/mid;
                else 
                    count += ((i/mid) + 1);
            if(count <= h){
                high = mid-1;
                ans = mid;
            }
            else 
                low = mid+1;
        }
        return ans;
    }
};