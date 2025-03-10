class Solution {
public:
    bool validPalindrome(string s) {
        int start = 0, end = s.length()-1;
        int firstError = 0, case1 = 1, case2 = 1;
        while(start < end){
            if(s[start] != s[end] && firstError == 0) {
                start = start+1;
                firstError = 1;
                continue;
            } else if(s[start] != s[end] && firstError == 1){
                case1 = 0;
                break;
            }
            start++;
            end--;
        }
        firstError = 0;
        if(case1)return true;
        start = 0; end = s.length()-1;
        while(start < end){
            if(s[start] != s[end] && firstError == 0) {
                end = end-1;
               
                firstError = 1;
                continue;
            } else if(s[start] != s[end] && firstError != 0){
                case2 = 0;
                break;
            }
            start++;
            end--;
        }

        return case1 || case2;
    }
};