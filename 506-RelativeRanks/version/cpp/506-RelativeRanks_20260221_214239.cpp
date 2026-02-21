// Last updated: 2/21/2026, 9:42:39 PM
1class Solution {
2public:
3    vector<string> findRelativeRanks(vector<int>& score) {
4        priority_queue<pair<int, int>> pq;
5        for(int i = 0 ; i < score.size(); i++)
6            pq.push({score[i], i});
7        vector<string> n(score.size(), "");
8        int count = 0;
9        while(pq.empty() == false){
10            pair<int, int> p = pq.top();
11            pq.pop();
12            if(count == 0)
13                n[p.second] = "Gold Medal";
14            else if(count == 1)
15                n[p.second] = "Silver Medal";
16            else if(count == 2)
17                n[p.second] = "Bronze Medal";
18            else 
19                n[p.second] = to_string(count+1);
20                count++;
21        }
22        return n;
23    }
24};