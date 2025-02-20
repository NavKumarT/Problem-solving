class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<string> ss;
        for(string s : nums)
            ss.insert(s);
        string currentStr = "";
        string res;
        int n = nums[0].length();
        func(ss, currentStr, n, res);
        return res;        
    }

    void func(unordered_set<string> &ss, string &curr, int n, string &res){
        if(res.length() > 0)
            return;
        if(curr.length() == n){
            if(ss.find(curr) == ss.end())
                res = curr;
            return;
        }
        if(curr.length() > n)
            return;
        string temp = curr;
        curr += "0";
        func(ss, curr, n, res);
        curr = temp + "1";
        func(ss, curr, n, res);
    }
};