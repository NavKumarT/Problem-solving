class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        // we store the count of occurences for each color in the first map 
        // we then store the color that each ball has in the second map 
        
        unordered_map<int, int> mp;  // color : count
        unordered_map<int, int> colors;   // ball : color 
        vector<int> ans; 

        for(int i = 0; i < queries.size(); i++){
            int currentBall = queries[i][0];
            int currentColorOfBall = colors[queries[i][0]];
            // decrease the count of current color and remove it from the map if count becomes 0
            if(colors.find(currentBall) != colors.end() && mp[currentColorOfBall] > 0)
                mp[currentColorOfBall]--;
            if(mp[currentColorOfBall] == 0)
                mp.erase(currentColorOfBall);
            // update the color of the ball and also update the count of the new color
            colors[currentBall] = queries[i][1];
            mp[queries[i][1]]++;
            ans.push_back(mp.size());
        }
        return ans;
    }
};