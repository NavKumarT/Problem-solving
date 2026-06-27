// Last updated: 6/27/2026, 11:53:00 AM
1class Solution {
2public:
3    int leastInterval(vector<char>& tasks, int n) {
4        unordered_map<char, int> hashMap;
5        int maxOcc = 0, maxTaskLength = 0;
6        for(char task : tasks){
7            hashMap[task]++;
8            if(hashMap[task] > maxTaskLength){
9                maxOcc = 1;
10                maxTaskLength = hashMap[task];
11            } else if(hashMap[task] == maxTaskLength){
12                maxOcc++;
13            }
14        }
15        int minSlotsRequired = ((n+1) * (maxTaskLength-1)) + maxOcc;
16        return minSlotsRequired > tasks.size() ? minSlotsRequired : tasks.size();
17        
18    }
19};