# Last updated: 7/30/2026, 12:41:05 PM
1class Solution:
2    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
3        group = defaultdict(list)
4        for s in strs:
5            count = [0] * 26
6            for ch in s:
7                count[ord(ch)-ord('a')] += 1
8            tuple_key = tuple(count)
9            group[tuple_key].append(s)
10        return list(group.values())
11        