// Last updated: 2/23/2026, 4:35:22 PM
1class Solution {
2public:
3    int lastStoneWeight(vector<int>& stones) {
4        priority_queue<int> pq;
5        for(int stone : stones)
6            pq.push(stone);
7        while(pq.size() >= 2 ){
8            int a = pq.top(); pq.pop();
9            int b = pq.top(); pq.pop();
10            if(a == b)
11                continue;
12            else 
13                pq.push(abs(a-b));
14        }
15        if(pq.size() > 0)
16            return pq.top();
17        return 0;
18    }
19};