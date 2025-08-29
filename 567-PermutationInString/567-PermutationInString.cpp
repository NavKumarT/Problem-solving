// Last updated: 8/29/2025, 9:50:29 PM
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int start = -1, end = -1;
        vector<int> count(26, 0);
        for(char ch : s1)
            count[ch-97]++;
        vector<int> temp = count;
        for(int i = 0; i < s2.length(); i++){
            if(temp[s2[i]-97] > 0){
                start = i;
                end = i;
                temp[s2[i]-97]--;
                int j = i+1;
                while(j < s2.length() && temp[s2[j]-97] > 0){
                    temp[s2[j]-97]--;
                    end = j;
                    j++;
                }
                if(end-start+1 == s1.length())
                    return true;
            } 
            temp = count;
        }
        return false;
    }
};