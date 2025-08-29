// Last updated: 8/29/2025, 9:47:48 PM
class Solution {
public:
    long long flowerGame(int n, int m) {
        // Get the Odd numbers between 1 and n
        long long odd1 = n % 2 == 0 ? n / 2 : n/2 + 1;

        // Get the odd numbers between 1 and m
        long long odd2 = m % 2 == 0 ? m / 2 : m/2 + 1;

        // Total pairs will be count of all pairs such that
        //  {odd from [1, n], even from [1, m]} + {odd from [1, m], even from [1, n]}
        return odd1*(m-odd2)  + odd2*(n-odd1);
    }
};