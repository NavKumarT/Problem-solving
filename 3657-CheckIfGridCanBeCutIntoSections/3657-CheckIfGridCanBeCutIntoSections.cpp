// Last updated: 8/29/2025, 9:47:32 PM
class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        // the number of intervals must be atleast 3
        vector<vector<int>> xIntervals;
        vector<vector<int>> yIntervals;
        for(vector<int> v : rectangles){
            xIntervals.push_back({v[0], v[2]});
            yIntervals.push_back({v[1], v[3]});
        }
        // merge the intervals if they can be merged and get the resulting 
        vector<vector<int>> mergedXIntervals = mergeIntervals(xIntervals, xIntervals.size());
        if(mergedXIntervals.size() >= 3)
            return true;
        vector<vector<int>> mergedYIntervals = mergeIntervals(yIntervals, yIntervals.size());
        if(mergedYIntervals.size() >= 3)
            return true;
        return false;
    }

    vector<vector<int>> mergeIntervals(vector<vector<int>> intervals, int n){
        vector<vector<int>> mergedIntervals;   
        sort(intervals.begin(), intervals.end());
        for(int i = 0; i < n; ){
            int start = intervals[i][0];
            int end = intervals[i][1];
            int j = i+1;
            while(j < n){
                if(intervals[j][0] < end){
                    if(intervals[j][1] > end){
                        end = intervals[j][1];
                    }
                    j++;
                } else {
                    mergedIntervals.push_back({start, end});
                    i = j;
                    break;
                }
            }
            if(j == n){
                mergedIntervals.push_back({start, end});
                break;
            }
        }
        return mergedIntervals;
    }
};