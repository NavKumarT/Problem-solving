// Last updated: 8/29/2025, 9:53:25 PM
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int low = 0, high = n-1;
        int ans = 0;
        while(low < high){
            ans = max(ans, min(height[low], height[high]) * (high-low));
            if(height[low] < height[high])
                low++;
            else 
                high--;
        }
        return ans;

    }
};