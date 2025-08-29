// Last updated: 8/29/2025, 9:51:29 PM
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        while(left < right){
            right = right & (right-1);
        }
        return right;
    }
};