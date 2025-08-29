// Last updated: 8/29/2025, 9:51:35 PM
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        for(int i = 0; i < numbers.size()-1; i++){
            int b = bSearch(numbers, i+1, numbers.size()-1, target-numbers[i]);
            if(b != -1)
                return {i+1, b+1};
        }
        return {-1, -1};
    }

    int bSearch(vector<int> &numbers, int low, int high, int sum){
        while(low<= high){
            int mid = low + (high-low)/2;
            if(numbers[mid] == sum){
                return mid;
            }
            else if (numbers[mid] > sum)
                high = mid-1;
            else 
                low = mid+1;
        }
        return -1;
    }
};