// Last updated: 2/21/2026, 8:44:42 PM
1class Solution {
2public:
3    vector<string> findRelativeRanks(vector<int>& score) {
4        vector<int> temp;
5        for(int n : score)
6            temp.push_back(n);
7        unordered_map<int, int> mp;
8        sort(temp.begin(), temp.end(), greater<int>());
9        for(int i = 0; i < temp.size(); i++)
10            mp[temp[i]] = i;
11        vector<string> ranks;
12        for(int n : score){
13            int index = mp[n];
14            if(index == 0)
15                ranks.push_back("Gold Medal");
16            else if(index == 1)
17                ranks.push_back("Silver Medal");
18            else if(index == 2)
19                ranks.push_back("Bronze Medal");
20            else 
21                ranks.push_back(to_string(index+1));
22        }
23        return ranks;
24    }
25};