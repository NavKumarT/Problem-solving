// Last updated: 10/26/2026, 10:13:16 PM
1class Solution {
2    public boolean isAnagram(String s, String t) {
3        if(t.length() != s.length()) {
4            return false;
5        }
6        
7        int[] count = new int[26];
8        for(int i = 0; i < s.length(); i++) {
9            count[s.charAt(i)-'a']++;
10        }
11        for(int i = 0; i < t.length(); i++) {
12            count[t.charAt(i)-'a']--;
13        }
14        for(int i : count){
15            if(i != 0)
16                return false;
17        }
18        return true;
19    }
20}