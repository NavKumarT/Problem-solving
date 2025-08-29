// Last updated: 8/29/2025, 9:47:34 PM
class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        for(int i = 0; i < nums.size(); i++){
            pq.push(make_pair(nums[i], i));
        }

        while(k > 0){
            pair<int, int> numPair = pq.top();
            pq.pop();
            int num = numPair.first;
            int index = numPair.second;
            num = multiplier * num;
            nums[index] = num;
            k--;
            pq.push(make_pair(num, index));
        }
        return nums;
    }
};