# Last updated: 8/2/2026, 12:39:40 PM
1class Solution:
2    def maxProfit(self, prices: List[int]) -> int:
3        max_profit_so_far = 0
4        n = len(prices)
5        max_price = prices[n-1]
6        for i in range(n-2, -1, -1):
7            max_price = max(max_price, prices[i])
8            curr = max_price - prices[i]
9            max_profit_so_far = max(max_profit_so_far, curr)
10        return max_profit_so_far