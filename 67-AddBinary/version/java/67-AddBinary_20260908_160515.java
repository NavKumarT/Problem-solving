// Last updated: 9/8/2026, 4:05:15 PM
1class Solution {
2    public String addBinary(String a, String b) {
3        int i = a.length()-1, j = b.length()-1;
4        if(i < 0 || j < 0){
5            return !a.isEmpty() ? a : b;
6        }
7        int carry = 0;
8        StringBuilder sb = new StringBuilder();
9        while(i >= 0 && j >= 0) {
10            int first = a.charAt(i)-'0',  second = b.charAt(j)-'0';
11            int total = first + second + carry;
12            sb.append(total % 2 == 1 ? '1' : '0');
13            carry = total / 2;
14            i--;
15            j--;
16        }
17        while(i >= 0) {
18            int first = a.charAt(i)-'0';
19            int total = first + carry;
20            sb.append(total % 2 == 1 ? '1' : '0');
21            carry = total / 2;
22            i--;
23        }
24        while(j >= 0) {
25            int first = b.charAt(j)-'0';
26            int total = first + carry;
27            sb.append(total % 2 == 1 ? '1' : '0');
28            carry = total / 2;
29            j--;
30        }
31        if(carry > 0)
32                    sb.append('1');
33
34        sb.reverse();
35        return sb.toString();
36    }
37}
38
39