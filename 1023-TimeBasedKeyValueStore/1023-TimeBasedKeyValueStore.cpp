// Last updated: 8/29/2025, 9:49:41 PM
class TimeMap {
private: 
    vector<vector<pair<int, string>>> store;
    unordered_map<string, int> mp;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        if(mp.find(key) == mp.end()){
            mp[key] = store.size();
            store.push_back({make_pair(timestamp, value)});
        } else {
            store[mp[key]].push_back(make_pair(timestamp, value));
        }
    }
    
    string get(string key, int timestamp) {
        if(mp.find(key) == mp.end())
            return "";
        int low = 0, high = store[mp[key]].size()-1;
        string floor = "";
        while(low <= high){
            int mid = low + (high-low)/2;
            if(store[mp[key]][mid].first == timestamp)
                return store[mp[key]][mid].second;
            else if(store[mp[key]][mid].first > timestamp)
                high = mid-1;
            else{
                floor = store[mp[key]][mid].second;
                low = mid+1;
            }
        }
        return floor;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */