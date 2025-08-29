// Last updated: 8/29/2025, 9:47:42 PM
class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        vector<vector<int>> res;
        for(int i = 0; i < meetings.size(); ){
            int start = meetings[i][0];
            int end = meetings[i][1];
            int j = i+1;
            while(j < meetings.size()){
                if(meetings[j][0] <= end){
                    if(meetings[j][1] >= end)
                    end = meetings[j][1];
                    j++;
                } else {
                    break;
                }
            }
            i = j;
            res.push_back({start, end});
        }
        int count = 0;
        for(int i = 0; i < res.size(); i++){
            count += res[i][1]-res[i][0]+1;
        }
        return days-count;
    }
};