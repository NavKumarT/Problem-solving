class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        mergeSortFunc(nums, 0, n-1);
        return nums;
    }

    void mergeSortFunc(vector<int> &nums, int start, int end){
        if(start == end)
            return;
        int mid = start + (end - start) / 2;
        mergeSortFunc(nums, start, mid);
        mergeSortFunc(nums, mid+1, end);
        merge(nums, start, mid, end);
    }

    void merge(vector<int> &arr, int l, int mid, int r){
        int m = mid - l + 1;
        int n = r - mid;
        vector<int> left, right;
        for(int i = l; i<= mid; i++)
            left.push_back(arr[i]);
        for(int i = mid+1; i <= r; i++)
            right.push_back(arr[i]);
        int i = 0,  j = 0, k = l;
        while(i < m && j < n){
            if(left[i] <= right[j]){
                arr[k] = left[i];
                i++;
                k++;
            } else {
                arr[k] = right[j];
                j++;
                k++;
            }
        }
        while(i < m){
            arr[k] = left[i];
            i++;
            k++;
        }
        while(j < n){
            arr[k] = right[j];
            j++;
            k++;
        }
    }
};