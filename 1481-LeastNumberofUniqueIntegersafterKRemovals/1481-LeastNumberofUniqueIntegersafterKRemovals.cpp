class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        for(int x : arr)
            mp[x]++;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        for(auto it : mp){
            pq.push(make_pair(it.second, it.first));
        }
        int i = 0;
        while(i < k){
            pair<int, int> p = pq.top();
            pq.pop();
            // i += p.first;
            if(k-i >= p.first){
                 i += p.first;
                 mp.erase(p.second);
            }
            else
            break;
        }
        return mp.size();
    }
};