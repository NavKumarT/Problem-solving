// Last updated: 2/9/2026, 7:28:20 PM
1class Solution {
2public:
3    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
4        unordered_map<string, int> mp;
5        for(int i = 0; i < list1.size(); i++) {
6            string s = list1[i];  
7            mp[s] = i;
8        }
9        int curr_min = INT_MAX;
10        vector<string> res;
11        for(int i = 0; i < list2.size(); i++){
12            if(mp.find(list2[i]) != mp.end()){
13                int curr = i + mp[list2[i]];
14                if(curr < curr_min){
15                    curr_min = curr;
16                    res.clear();
17                    res.push_back(list2[i]);
18                } else if(curr == curr_min){
19                    res.push_back(list2[i]);
20                }
21            }
22        }
23        return res;
24    }
25};