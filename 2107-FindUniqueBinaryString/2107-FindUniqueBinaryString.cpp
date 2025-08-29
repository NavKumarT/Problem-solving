// Last updated: 8/29/2025, 9:48:39 PM
class Solution {
public:
    // solution uses hashing in addition to backtracking, 
    // generate all possible binary stirngs and check if the 
    // hashtable has those. Once you find a binary string that
    //  is not present in the hashtable, 
    // return directly in the subsequent recusrsive calls 
   
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