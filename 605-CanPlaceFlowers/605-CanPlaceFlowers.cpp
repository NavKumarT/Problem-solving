// Last updated: 8/29/2025, 9:50:26 PM
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        int prev = -1;
        for(int i = 0;i < flowerbed.size(); i++){
            if(flowerbed[i] == 0 && prev != 1){
                count++;
                prev = 1;
            } else if(flowerbed[i] == 1 && prev == 1){
                count--;
            } else {
                prev = flowerbed[i];
            }
        }
        return count >= n;
    }
};