// Last updated: 04/06/2025, 22:33:05
class Solution {
public:
    int getSum(int a, int b) {
        while(b != 0){
            unsigned int carry = (unsigned int)(a&b) << 1;
            a = a ^ b;
            b = carry;
        }
        return a;
    }
};