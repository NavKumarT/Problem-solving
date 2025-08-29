// Last updated: 8/29/2025, 9:49:32 PM
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if(stones.size() == 1)
            return stones[0];

        priority_queue<int> pq;
        for(int stone : stones)
            pq.push(stone);
        while(pq.size() > 1){
            int a = pq.top(); pq.pop();
            int b = pq.top(); pq.pop();
            int res = abs(a-b);
            if(res > 0) pq.push(res);
        }
        if(pq.size() > 0)
            return pq.top();
        else 
            return 0;
    }
};