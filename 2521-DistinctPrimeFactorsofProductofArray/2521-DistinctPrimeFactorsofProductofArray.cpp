class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        // if a number is prime add that to the set 
        // else find all the prime factors of the number and add them to the set 
        // n - > size of nums array 
        // m -> largest number in nums 
        // Time : O(n * root(m))
        unordered_set<int> s;
        for(int i : nums){
            if(isPrime(i)){
                s.insert(i);
            } else{
                // find all the prime factors of the number
                int n = i;
                if( n == 2 || n == 3){
                    s.insert(n);
                    continue;
                }
                while(n%2 == 0){
                    s.insert(2);
                    n /= 2;
                }
                while(n%3 == 0){
                    s.insert(3);
                    n /= 3;
                }
                for(int i = 5; i*i <= n; i+=6){
                    while(n%i == 0){
                        s.insert(i);
                        n /= i;
                    }
                    while(n%(i+2) == 0){
                        s.insert(i+2);
                        n /= (i+2);
                    }
                }
                if(n > 3)
                    s.insert(n);
            }
        }
        return s.size();
    }


    bool isPrime(int n){
        if(n == 1)
            return false;
        if(n == 2 || n == 3)
            return true;
        if(n % 2 == 0 || n % 3 == 0)
            return false;
        for(int i = 5; i*i <= n; i+=6){
            if(n % i == 0 || n % (i+2) == 0){
                return false;
            }
        }
        return true;
    }
};