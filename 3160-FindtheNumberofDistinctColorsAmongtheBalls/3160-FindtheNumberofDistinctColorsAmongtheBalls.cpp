class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        // map : we store the count of occurences for each color 
        unordered_map<int, int> mp;
        // Color vector : To store the color of the balls so that we can reduce the count for prev color 
        // and increase the color for the new color
        // vector<int> colors(limit+1, -1);
        unordered_map<int, int> colors;
        // To return the ans
        vector<int> ans; 
        for(int i = 0; i < queries.size(); i++){
            int temp = colors[queries[i][0]];
            // if(temp != -1)
            if(colors.find(queries[i][0]) != colors.end() && mp[temp] > 0)
                mp[temp]--;
            if(mp[temp] == 0)
                mp.erase(temp);
            colors[queries[i][0]] = queries[i][1];
            mp[queries[i][1]]++;
            ans.push_back(mp.size());
        }
        return ans;
    }
};