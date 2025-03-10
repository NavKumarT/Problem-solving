class Solution {
public:
    bool isPalindrome(string s) {
        string temp = "";
        for(char x : s){
            if((x >= 48 && x <= 57) ||( x >= 97 && x <= 122))
                temp += x;
            if(x >= 65 && x <= 90)
                temp += char(x + 32);
        }
        int start = 0, end = temp.length()-1;
        while(start < end){
            if(temp[start] != temp[end])
                return false;
            start++;
            end--;
        }
       
        return true;
    }
};