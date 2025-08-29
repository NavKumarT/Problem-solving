// Last updated: 8/29/2025, 9:47:30 PM
class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            bool basketFound = false;
            for(int j = 0; j < n; j++){
                if(baskets[j] >= fruits[i]){
                    baskets[j] = -1;
                    basketFound = true;
                    break;
                }
            }
            if(basketFound)
                continue;
            ans++;
        }
        return ans;
    }
};