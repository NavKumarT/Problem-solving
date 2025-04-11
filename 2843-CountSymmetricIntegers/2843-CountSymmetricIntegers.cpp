// Last updated: 11/04/2025, 09:55:45
class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0;
        for(int i = low; i <= high; i++){
            string temp = to_string(i);
            if(temp.length() % 2 == 0){
                int first = 0, second = 0;
                for(int i = 0; i < temp.length(); i++){
                    if(i < temp.length()/2){
                        first += (temp[i]-48);
                    } else {
                        second += (temp[i]-48);
                    }
                }
                if(first == second)
                    count++;
            }
        }
        return count;
    }
};