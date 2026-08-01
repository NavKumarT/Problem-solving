# Last updated: 8/1/2026, 5:41:56 PM
1class Solution:
2    def maxProfit(self, prices: List[int]) -> int:
3        profit = 0
4        for i in range(1, len(prices)):
5            if prices[i] > prices[i-1]:
6                profit += prices[i]-prices[i-1]
7        return profit