// Last updated: 8/29/2025, 9:48:37 PM
class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        priority_queue<string, vector<string>, Solution> pq;
        for(string s : nums){
            pq.push(s);
        }
        for(int i = 0; i < k-1 ;i++){
            pq.pop();
        }
        return pq.top();
    }

    bool operator()(string s1, string s2){
        int m = s1.length();
        int n = s2.length();
        if(m > n) 
            return false;
        else if(m < n)
            return true;
        int i = 0;
        while(i < m){
            if(s1[i] < s2[i])
                return true;
            else if(s1[i] > s2[i])
                return false;
            else 
                i++;
        }
        return true;
    }
};