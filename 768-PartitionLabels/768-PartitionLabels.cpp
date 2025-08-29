// Last updated: 8/29/2025, 9:50:11 PM
class Solution {
public:
    vector<int> partitionLabels(string s) {
        // base case when string has only on char, then only one partition is possible 
        if(s.length() == 1)
            return {1};

        vector<int> ans; // Final vector to return 
        unordered_map<int, int> mp;  // to store the number of occurences of each character
        for(char ch : s)
            mp[ch]++;
        
        // a variable length window to track if we have all the 
        // occurences of different char in the same window.
        int start = 0, end = 0, count = 0;
        unordered_set<char> ss;
        for(int i = 0; i < s.length(); i++){
            // if we already have the char in the window
            // decrement the count and increase the window
            if(ss.find(s[i]) != ss.end()){
                count--;
                end++;
            } else { // take in the new element
                ss.insert(s[i]);
                count += mp[s[i]]-1;
                end++;
            }
            // if count becomes 0, we have all the occurences, so we restart the window
            // after pusing the previous window to our ans
            if(count == 0){
                ans.push_back(end-start);
                ss.clear();
                start = i+1;
                end = i+1;
            }
        }  
        return ans; 
    }
};