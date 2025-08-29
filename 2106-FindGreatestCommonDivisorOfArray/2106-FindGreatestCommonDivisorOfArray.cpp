// Last updated: 8/29/2025, 9:48:41 PM
class Solution {
public:
    int findGCD(vector<int>& nums) {
        int smallest = nums[0]; // smallest num in the array 
        int largest = nums[0];  // largest num in the array 
        for(int i : nums){
            smallest = min(smallest, i);
            largest = max(largest, i);
        }
        // find gcd using euclidean algorithm 
        while(smallest != 0 && largest != 0){
            int temp = smallest;
            smallest = largest % smallest;
            largest = temp;
        }
        return smallest > 0 ? smallest : largest;
    }
};