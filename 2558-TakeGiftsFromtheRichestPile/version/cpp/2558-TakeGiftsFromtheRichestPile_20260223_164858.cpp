// Last updated: 2/23/2026, 4:48:58 PM
1class Solution {
2public:
3    long long pickGifts(vector<int>& gifts, int k) {
4        priority_queue<int> pq;
5        for(int gift : gifts)
6            pq.push(gift);
7        while(k--){
8            int a = pq.top(); pq.pop();
9            pq.push(floor(sqrt(a)));
10        }
11        long long ans = 0;
12        while(pq.empty() == false){
13            ans += pq.top();
14            pq.pop();
15        }
16        return ans;
17    }
18};