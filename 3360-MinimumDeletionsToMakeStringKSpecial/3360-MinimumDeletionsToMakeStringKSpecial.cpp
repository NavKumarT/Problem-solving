// Last updated: 8/29/2025, 9:47:46 PM
class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> count(26, 0);
        for(char ch : word)
            count[ch-97]++;
        int ans = INT_MAX;
        for(int num : count){
            int target = num;
            int curr = 0;
            for(int num1 : count)
                if(num1 < num)
                    curr += num1;
                else if(abs(num1-num) > k)
                    curr += num1-num-k;
            ans = min(curr, ans);
        }
        return ans;
    }
};