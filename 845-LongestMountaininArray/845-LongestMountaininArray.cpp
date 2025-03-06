class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();

        if(n < 3)
            return 0;
        vector<int> lis(n, 1);
        vector<int> lis1(n, 1);
        for(int i = 1; i < n; i++){
            // for(int j = 0; j < i; j++){
                if(arr[i] > arr[i-1]){
                    lis[i] = max(lis[i], lis[i-1]+1);
                }
            // }
        }
        // reverse(arr.begin(), arr.end());
        for(int i = n-2; i >= 0; i--){
            // for(int j = n-1; j > i; j--){
                if(arr[i] > arr[i+1]){
                    lis1[i] = max(lis1[i], lis1[i+1]+1);
                }
            // }
        }
        int ans = INT_MIN;
        for(int i = 1; i <n-1; i++){
            if(lis[i] != 1 && lis1[i] != 1)
            ans = max(ans, lis[i]+lis1[i]-1);
        }
        for(int i : lis)
            cout << i << " ";
        cout << endl;
        for(int i : lis1)
            cout << i << " ";
        if(ans <= 2)
            return 0;
        return ans;
    }
};