class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int n=arr.size();
        int sum=0;
        long long count=0;

        for(int num: arr) {
            sum+=num;
            if((sum & 1) != 0) count++;
        }

        long long finalCount = (count*(n-count)+count)%MOD;

        return int(finalCount);
    }
};