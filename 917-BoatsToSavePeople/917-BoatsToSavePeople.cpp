// Last updated: 8/29/2025, 9:49:56 PM
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        sort(people.begin(), people.end());
        int low = 0, high = n-1;
        int count = 0;
        while(low < high){
            int weight = people[high];
            if(weight == limit){
                count++;
                high--;
            } else if(weight + people[low] <= limit){
                count++;
                high--;
                low++;
            } else {
                count++;
                high--;
            }
        }
        if(low == high)
        count++;
        return count;
        
    }
};