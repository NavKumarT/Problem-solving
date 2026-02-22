// Last updated: 2/22/2026, 11:43:40 PM
1class Solution {
2public:
3    int lastStoneWeight(vector<int>& stones) {
4        priority_queue<int> pq;
5        for(int stone : stones)
6            pq.push(stone);
7        while(pq.size() > 1){
8            int a = pq.top(); pq.pop();
9            int b = pq.top(); pq.pop();
10            if(a == b)
11                continue;
12            pq.push(abs(a-b));
13        }
14        if(pq.empty())
15            return 0;
16        else 
17            return pq.top();
18    }
19};