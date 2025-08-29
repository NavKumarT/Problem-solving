// Last updated: 8/29/2025, 9:49:37 PM
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = INT_MIN, high =0;
        for(int weight : weights){
             high = high + weight;
             low = max(low, weight);
        }
        int ans = INT_MAX;
        while(low <= high){
            int mid = low + (high-low)/2;
            int daysRequired = computeDays(weights, mid, weights.size());
            cout <<daysRequired << " " << mid << endl;
            if(daysRequired <= days){
                ans = mid;
                high = mid-1;
            }
            else 
            low = mid+1;
        }
        return ans;
    }

    int computeDays(vector<int> &weights, int x, int n){
        int nn = 0;
        int temp = 0;
        for(int i = 0; i < n; i++){
            temp += weights[i];
            if(temp > x)
            {    nn++;
            temp = weights[i];}
            else if(temp == x){
                nn++;
                temp = 0;
            }
        }
        if(temp > 0)
            nn++;
        return nn;
    }
};