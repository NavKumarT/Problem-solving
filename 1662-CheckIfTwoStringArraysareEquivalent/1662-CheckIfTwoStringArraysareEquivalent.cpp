// Last updated: 3/10/2025, 10:31:06 PM
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int i = 0, j = 0;
        int c1 = 0, c2 = 0;
        while(c1 < word1.size() && c2 < word2.size()){
            string a = word1[c1];
            string b = word2[c2];

            if(a[i] != b[j])
                return false;
            i++;
            j++;
            if(i >= word1[c1].length()){
                c1++;
                i = 0;
            }
            if(j >= word2[c2].length()){
                c2++;
                j = 0;
            }
        }
        return c1 == word1.size() && c2 == word2.size();
    }
};