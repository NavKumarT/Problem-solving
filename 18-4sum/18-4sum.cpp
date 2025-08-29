// Last updated: 8/29/2025, 9:53:21 PM
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        if(n <= 3)
            return res;
        for(int i = 0; i < nums.size()-3; i++){
            long long sum = target - nums[i];
            vector<int> numsTemp(nums.begin()+i+1, nums.begin()+n);
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            vector<vector<int>> temp = threeSum(nums[i], numsTemp, sum);
            for(vector<int> vec : temp)
                res.push_back(vec);
        }
        return res;
    }

    vector<vector<int>> threeSum(int add, vector<int>& nums, long long s) {
        // sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for(int i = 0; i < nums.size()-2; i++){
            long long sum = s - nums[i];
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            int low = i+1, high = nums.size()-1;
            while(low < high){
                if(nums[low] + nums[high] == sum){
                    res.push_back({add, nums[i], nums[low], nums[high]});
                    do{
                        low++;
                    }while(low >= 0 && low < nums.size() && nums[low-1] == nums[low]);
                    high--;
                } else if(nums[low] + nums[high] < sum)
                    low++;
                else 
                    high--;
            }
        }
        return res;
    }
};