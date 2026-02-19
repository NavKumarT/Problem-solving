// Last updated: 2/19/2026, 11:27:49 AM
1class Solution {
2public:
3    int numRescueBoats(vector<int>& people, int limit) {
4        int low = 0, high = people.size()-1;
5        int count = 0;
6        sort(people.begin(), people.end());
7        while(low <= high){
8            int totalWeight = people[low] + people[high];
9            if(totalWeight <= limit){
10                high--;
11                low++;
12            } else {
13                high--;
14            }
15             count++;
16        }
17        return count;
18    }
19};