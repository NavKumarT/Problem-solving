# Last updated: 8/5/2026, 12:56:12 PM
1# The guess API is already defined for you.
2# @param num, your guess
3# @return -1 if num is higher than the picked number
4#          1 if num is lower than the picked number
5#          otherwise return 0
6# def guess(num: int) -> int:
7
8class Solution:
9    def guessNumber(self, n: int) -> int:
10        low, high = 1, n
11        while low <= high:
12            mid = low + (high-low)//2
13            if guess(mid) == 0:
14                return mid
15            elif guess(mid) == -1:
16                high = mid-1
17            else:
18                low = mid+1
19        return -1
20
21        