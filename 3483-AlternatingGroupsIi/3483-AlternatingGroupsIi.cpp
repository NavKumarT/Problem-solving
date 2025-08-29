// Last updated: 8/29/2025, 9:47:38 PM
class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        int ans = 0;
        int newStart = 0;
        vector<int> memo(n, 0);
        if(k > n)
            return 0;
        for(int i = 0; i < n; ){
            cout << i << endl;
            if(i > 0 && memo[i-1] == 1){
                if(i > 0 && k%2 == 0 && colors[i-1] == colors[(i+k-1)%n]){
                    memo[i] = 1;
                    ans++;
                }
                if(i > 0 && k%2 != 0 && colors[i-1] != colors[(i+k-1)%n]){
                    memo[i] = 1;
                    ans++;
                }
                i = i+1;
                continue;
            } 
            bool isWindowGood = true;
            for(int j = i; j < i+k-1; j++){
                if(colors[j%n] == colors[(j+1)%n]){
                    i = (j+1);
                    isWindowGood = false;
                    break;
                }
            }
            if(isWindowGood){memo[i] = 1;
            ans++;
            i = i+1;}
        }
        return ans;
    }
};