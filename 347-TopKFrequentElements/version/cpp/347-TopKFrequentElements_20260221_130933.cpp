// Last updated: 2/21/2026, 1:09:33 PM
1class Solution {
2public:
3    vector<int> topKFrequent(vector<int>& nums, int k) {
4        // {number : count_of_the_number} {1:3, 2:2, 3:1}
5        unordered_map<int, int> mp;
6        for(int num : nums)
7            mp[num]++;
8        // Min Heap of size k
9        // heap constituets {count_of_the_number, number}
10priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
11        for(auto it : mp){
12            if(pq.size() >= k){
13                if(pq.top().first < it.second){
14                    pq.pop();
15                    pq.push({it.second, it.first});
16                }
17            } else {
18                 pq.push({it.second, it.first});
19            }
20            cout << it.second << " " << it.first << endl;
21        }
22        vector<int> r;
23        while(pq.empty() == false){
24            r.push_back(pq.top().second);
25            pq.pop();
26        }
27        return r;
28    }
29};