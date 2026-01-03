// Last updated: 1/3/2026, 12:24:52 PM
class Solution {
public:
    string sortVowels(string s) {
        vector<int> indices; 
        vector<char> vowels;
        vector<char> ALL_VOWELS = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};
        unordered_set<char> setVowels(ALL_VOWELS.begin(), ALL_VOWELS.end());
        for(int i = 0; i < s.length(); i++){
            if(setVowels.find(s[i]) != setVowels.end()){
                indices.push_back(i);
                vowels.push_back(s[i]);
            }
        }
        sort(vowels.begin(), vowels.end());
        for(int i = 0; i < vowels.size(); i++)
            s[indices[i]] = vowels[i];
        return s;
    }
};