// Last updated: 8/29/2025, 9:52:38 PM
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        string curr;
        int parts = 0;
        int i = 0;
        int n = s.length();
        vector<string> ans;
        backtrack(curr,ans,i,parts,n,s);
        return ans;
    }

    void backtrack(string curr, vector<string> &ans, int i, int parts, int n, string s){
        cout << curr << " " << i  << " " << parts  << " " << n << endl;
        if(parts == 4 && i == n){
            ans.push_back(curr);
            return;
        }
        if(i >= n || parts > 4)
            return;
        for(int k = 1; k <= 3; k++){
            if(i + k > n)
                continue;
            string temp = s.substr(i, k);
            if((temp.length() > 1 && temp[0] == '0') || (stoi(temp) > 255))
                continue;
            string original = curr;
            curr += temp;
            if(parts < 3)
                curr += '.';
            parts++;
            backtrack(curr,ans,i+k,parts,n,s);
            curr = original;
            parts--;
        }
    }
};