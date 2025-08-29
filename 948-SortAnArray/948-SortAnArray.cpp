// Last updated: 8/29/2025, 9:49:52 PM
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int low = 0, high = nums.size()-1;
        mergeSort(nums, low, high);
        return nums;
    }

    void mergeSort(vector<int> &nums, int low, int high){
        if(low < high){
            int mid = low + (high-low)/2;
            mergeSort(nums, low, mid);
            mergeSort(nums, mid+1, high);
            merge(nums, low, mid, high);
        }
    }

    void merge(vector<int> &nums, int low, int mid, int high){
        int n1 = mid-low+1, n2 = high-mid;
        vector<int> firstHalf(n1), secondHalf(n2); // copies of the 2 halves of the array 
        for(int i = 0; i < n1; i++){
            firstHalf[i] = nums[low+i];
        }
        for(int i = 0; i < n2; i++){
            secondHalf[i] = nums[mid+i+1];
        }
        int m = 0, n = 0; // both pointers point to the first element of the copies 
        int k = low; // first element of the actual array 
        while(m < n1 && n < n2){
            if(firstHalf[m] <= secondHalf[n]){
                nums[k] = firstHalf[m];
                m++;
                k++;
            } else if(secondHalf[n] < firstHalf[m]){
                nums[k] = secondHalf[n];
                n++;
                k++;
            }
        }
        while(m < n1){
            nums[k] = firstHalf[m];
            m++;
            k++;
        }
        while(n < n2){
            nums[k] = secondHalf[n];
            n++;
            k++;
        }
    }
};