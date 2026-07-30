# Last updated: 7/30/2026, 12:32:53 PM
1class Solution:
2    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
3        hashmap = {}
4        for s in strs:
5            freqMap = "".join(sorted(s))
6            if freqMap in hashmap:
7                hashmap[freqMap].append(s)
8            else:
9                hashmap[freqMap] = [s]
10        
11        return list(hashmap.values())
12        