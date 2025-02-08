class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int stone : stones)
            pq.push(stone);
        while(pq.size() > 1){
            int firstHeavy = pq.top();
            pq.pop();
            int secondHeavy = pq.top();
            pq.pop();
            if(firstHeavy == secondHeavy)
                continue;
            else
                pq.push(firstHeavy - secondHeavy);
        }
        if(pq.size() == 1)
            return pq.top();
        return 0;
    }
};