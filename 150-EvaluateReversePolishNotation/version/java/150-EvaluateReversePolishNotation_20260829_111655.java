// Last updated: 8/29/2026, 11:16:55 AM
1import java.util.ArrayDeque;
2import java.util.Deque;
3
4class Solution {
5    public int evalRPN(String[] tokens) {
6        Deque<Integer> stack = new ArrayDeque<>();
7
8        for (String token : tokens) {
9
10            if (!isOperator(token)) {
11                stack.push(Integer.parseInt(token));
12                continue;
13            }
14
15            int b = stack.pop();
16            int a = stack.pop();
17
18            switch (token) {
19                case "+":
20                    stack.push(a + b);
21                    break;
22                case "-":
23                    stack.push(a - b);
24                    break;
25                case "*":
26                    stack.push(a * b);
27                    break;
28                case "/":
29                    stack.push(a / b);
30                    break;
31            }
32        }
33
34        return stack.pop();
35    }
36
37    private boolean isOperator(String token) {
38        return token.equals("+")
39                || token.equals("-")
40                || token.equals("*")
41                || token.equals("/");
42    }
43}