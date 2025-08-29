// Last updated: 8/29/2025, 9:50:20 PM
class Solution {
public:
    bool validPalindrome(string s) {
        int low = 0, high = s.length()-1;
        bool isFirst = true, path1 = true;
        while(low < high){
            if(s[low] != s[high]){
                if(isFirst){
                     low = low + 1;
                     isFirst = false;
                }
                else {
                    path1 = false;
                    break;
                }
            } else {
                low++;
                high--;
            }
        }
        low = 0, high = s.length()-1;
        bool path2 = true;
        isFirst = true;
        while(low < high){
            if(s[low] != s[high]){
                if(isFirst){
                    high = high-1;
                    isFirst = false;
                }
                else {
                    path2 = false;
                    break;
                }
            }
            else {
                low++;
                high--;
            }
        }
        if(path1 || path2)
            return true;
        return false;
    }
};