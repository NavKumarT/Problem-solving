// Last updated: 8/29/2025, 9:50:02 PM
class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        if(n < 3)
            return 0;
        vector<int> lis(n, 1);
        vector<int> lis1(n, 1);
        for(int i = 1; i < n; i++){
                if(arr[i] > arr[i-1]){
                    lis[i] = max(lis[i], lis[i-1]+1);
                }
        }
        for(int i = n-2; i >= 0; i--){
                if(arr[i] > arr[i+1]){
                    lis1[i] = max(lis1[i], lis1[i+1]+1);
                }
        }
        int ans = INT_MIN;
        for(int i = 1; i <n-1; i++){
            if(lis[i] != 1 && lis1[i] != 1)
            ans = max(ans, lis[i]+lis1[i]-1);
        }
        if(ans <= 2)
            return 0;
        return ans;
    }
};