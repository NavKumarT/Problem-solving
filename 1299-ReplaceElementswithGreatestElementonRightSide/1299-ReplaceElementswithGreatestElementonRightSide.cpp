class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        int largest = -1;
        for(int i = n-1; i >= 0; i--){
            int temp = arr[i];
            arr[i] = largest;
            largest = max(largest, temp);
        }
        return arr;
    }
};