// Last updated: 8/29/2025, 9:48:04 PM
class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long sum = 0; // we will return this 
        priority_queue<int> pq;
        for(int gift : gifts)
            pq.push(gift);
        while(k > 0){
            int gift = pq.top(); pq.pop();
            int root = sqrt(gift);
            pq.push(root);
            k--;
        }
        while(pq.empty() == false){
            sum += pq.top();
            pq.pop();
        }
        return sum;
    }
};