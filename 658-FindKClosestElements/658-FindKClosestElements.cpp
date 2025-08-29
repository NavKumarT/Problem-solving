// Last updated: 8/29/2025, 9:50:23 PM
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        pair<pair<int, int>, bool> index = findElement(arr, x);
        vector<int> temp;
        int left = index.first.first, right = index.first.second;
        bool isPresent = index.second;
        if(isPresent){
            temp.push_back(x);
            k--;
        }
        
        while(left > -1 && right < arr.size()){
            if(k == 0)
                break;
            if(abs(arr[left]-x) <= abs(arr[right]-x)){
                temp.push_back(arr[left]);
                left--;
            } else {
                temp.push_back(arr[right]);
                right++;
            }
            k--;
        }
        while(left > -1 && k != 0){
             temp.push_back(arr[left]);
            left--;
            k--;
        }
         while(right < arr.size() && k != 0){
             temp.push_back(arr[right]);
             right++;
             k--;
        }
        sort(temp.begin(), temp.end());
        return temp;
    }

    pair<pair<int, int>, bool> findElement(vector<int> &arr, int target){
        int low = 0, high = arr.size()-1;
        int ceil = arr.size(), floor = -1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(arr[mid] == target){
                return make_pair(make_pair(mid-1, mid+1), true);
            }
            else if(arr[mid] > target){
                high = mid-1;
                ceil = mid;
            } else {
                low = mid+1;
                floor = mid;
            }
        }
        return make_pair(make_pair(floor, ceil), false);
    }
};