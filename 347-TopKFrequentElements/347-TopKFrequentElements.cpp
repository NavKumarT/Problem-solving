class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        priority_queue<pair<int, int>> pq;
        for(int x : nums)
            mp[x]++;
        for(auto it : mp){
            pq.push(make_pair(it.second, it.first));
            if(pq.size() > k){
                vector<pair<int, int>> vec;
                int m = 0;
                while(m < k){
                    vec.push_back(pq.top());
                    pq.pop();
                    m++;
                }
                pq.pop();
                for(pair<int, int> p : vec)
                    pq.push(p);
            }
        }        
        vector<int> ans;
        for(int i = 0; i < k; i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};