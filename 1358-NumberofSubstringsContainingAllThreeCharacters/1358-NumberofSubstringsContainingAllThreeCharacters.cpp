class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans = 0;
        int start = 0;
        int end = 0;
        int n = s.length();

        unordered_map<char, int> ss;
        ss[s[start]]++;
        while(end < n && start <= end){
            if(ss.size() == 3){
                ans += n-end;
                ss[s[start]]--;
                if(ss[s[start]] == 0)
                    ss.erase(s[start]);
                start++;
            } else {
                end++;
                ss[s[end]]++;
            }
        }
        return ans;
    }
};