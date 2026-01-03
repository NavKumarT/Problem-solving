// Last updated: 1/3/2026, 12:24:35 PM
class Solution {
public:
    int maxFreqSum(string s) {
        vector<int> freq(26, 0);
        for(char ch : s){
            freq[ch-'a']++;
        }
        int vowelMax = 0, consMax = 0;
        for(char ch : s){
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
                vowelMax = max(vowelMax, freq[ch-'a']);
            } else {
                consMax = max(consMax, freq[ch-'a']);
            }
        }
        return consMax + vowelMax;
    }
};