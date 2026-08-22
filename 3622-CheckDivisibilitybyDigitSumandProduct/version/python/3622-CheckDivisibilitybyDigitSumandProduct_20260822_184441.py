# Last updated: 8/22/2026, 6:44:41 PM
1class Solution:
2    def checkDivisibility(self, n: int) -> bool:
3        summation = 0
4        product = 1
5        temp = n
6        while temp > 0:
7            digit = temp % 10
8            summation += digit
9            product *= digit
10            temp /= 10
11            temp = int(temp)
12        if n % (summation+product) == 0:
13            return True
14        return False