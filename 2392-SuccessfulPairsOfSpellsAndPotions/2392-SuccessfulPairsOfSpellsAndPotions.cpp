// Last updated: 8/29/2025, 9:48:22 PM
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        int i = 0;
        for(int spell : spells){
            int ceil = getCeil(potions, success, spell);
            if(ceil == -1){
                spells[i] = 0;
            } else {
                spells[i] = potions.size()-ceil;
            }
            i++;
        }
        return spells;
    }

    int getCeil(vector<int> &potions, long long target, long long spell){
        int ceil = -1;
        int low = 0, high = potions.size()-1, n = potions.size();
        while(low <= high){
            int mid = low + (high-low)/2;
            long long unsigned int curr = potions[mid] * spell;
            if( curr == target){
                if(mid == 0 || potions[mid] != potions[mid-1]){
                    return mid;
                }
                else {
                    ceil = mid;
                    high = mid-1;
                }
            } else if(curr > target){
                ceil = mid;
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        return ceil;
    }
};