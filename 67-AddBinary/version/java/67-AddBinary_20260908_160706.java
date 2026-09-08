// Last updated: 9/8/2026, 4:07:06 PM
1class Solution {
2    public String addBinary(String a, String b) {
3        int i = a.length() - 1;
4        int j = b.length() - 1;
5        int carry = 0;
6
7        StringBuilder sb = new StringBuilder();
8
9        while (i >= 0 || j >= 0 || carry > 0) {
10            int sum = carry;
11
12            if (i >= 0) {
13                sum += a.charAt(i--) - '0';
14            }
15
16            if (j >= 0) {
17                sum += b.charAt(j--) - '0';
18            }
19
20            sb.append(sum % 2);
21            carry = sum / 2;
22        }
23
24        return sb.reverse().toString();
25    }
26}