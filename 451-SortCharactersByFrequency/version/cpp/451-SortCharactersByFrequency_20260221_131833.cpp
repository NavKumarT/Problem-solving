// Last updated: 2/21/2026, 1:18:33 PM
1class Solution {
2public:
3    string frequencySort(string s) {
4        unordered_map<char, int> mp;
5        for(char ch : s)
6            mp[ch]++;
7        priority_queue<pair<int, char>> pq;
8        for(auto it : mp)
9            pq.push({it.second, it.first});
10        string st = "";
11        while(pq.empty() == false){
12            int occ = pq.top().first;
13            while(occ){
14                st += pq.top().second;
15                occ--;
16            }
17            pq.pop();
18        }
19        return st;
20    }
21};