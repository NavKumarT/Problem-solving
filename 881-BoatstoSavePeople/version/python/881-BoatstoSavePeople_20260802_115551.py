# Last updated: 8/2/2026, 11:55:51 AM
1class Solution:
2    def numRescueBoats(self, people: List[int], limit: int) -> int:
3        n = len(people)
4        people.sort()
5        left, right = 0, n-1
6        count_of_boats = 0
7        while left <= right:
8            curr_weight = people[left] + people[right]
9            if curr_weight <= limit:
10                count_of_boats += 1
11                left += 1
12                right -= 1
13            elif people[right] <= limit:
14                count_of_boats += 1
15                right -= 1
16            else:
17                return -1
18        return count_of_boats
19
20