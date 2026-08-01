// Last updated: 8/1/2026, 8:50:31 PM
1class Solution {
2    public String mergeAlternately(String word1, String word2) {
3        int m = word1.length(), n = word2.length(), i = 0, j = 0;
4        String merged = "";
5        boolean first = true;
6        while(i < m && j < n){
7            if(first){
8                merged += word1.charAt(i);
9                i++;
10            }
11            else {
12                merged += word2.charAt(j);
13                j++;
14            }
15            first = !first;
16        }
17        while(i < m){
18            merged += word1.charAt(i);
19            i++;
20        }
21        while(j < n){
22            merged += word2.charAt(j);
23            j++;
24        }
25        return merged;
26    }
27}