// Last updated: 8/29/2025, 9:50:44 PM
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int count = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = 0, j = 0, m = g.size(), n = s.size();
        while(i < m && j < n){
            if(g[i] <= s[j]){
                count++;
                i++;
                j++;
            } else {
                j++;
            }
        }
        return count;
    }
};