class Solution {
public:
    string largestGoodInteger(string num) {
        string largest = "";
        string temp = num.substr(0, 1);
        for(int i = 1; i < num.size(); i++){
            if(num[i] == num[i-1] && temp.length() < 3)
                temp = temp + num[i];
            else 
                temp = num[i];
            if(temp > largest && temp.length() == 3)
                largest = temp;
        }
        return largest;
    }
};