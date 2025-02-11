class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = s.length();
        int wordLength = 0;
        for(int i = length-1; i >= 0; i--){
            if(s[i] != ' '){
                wordLength++;
                continue;
            } else {
                if(wordLength > 0)
                    return wordLength;
            }
        }
        return wordLength;
    }
};