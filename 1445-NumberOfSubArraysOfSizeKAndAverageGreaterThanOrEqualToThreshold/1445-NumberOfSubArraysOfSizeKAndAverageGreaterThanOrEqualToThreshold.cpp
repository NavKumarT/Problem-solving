// Last updated: 8/29/2025, 9:49:14 PM
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int curr = 0, ans = 0, start = 0, end = 0;
        // get the avg of the first window 
        for(int i = 0; i < k; i++){
            int num = arr[i];
            curr += num;
        }
        float avg = curr / k;
        if(avg >= threshold)
            ans++;
        for(int i = k; i < arr.size(); i++){
            curr -= arr[i-k];
            curr += arr[i];
            avg = curr / k;
            if(avg >= threshold)
                ans++;
        }
        return ans;
    }
};