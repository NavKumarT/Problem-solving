// Last updated: 8/29/2026, 11:14:44 AM
1import java.sql.Array;
2import java.util.ArrayDeque;
3import java.util.Deque;
4
5class Solution {
6    public int evalRPN(String[] tokens) {
7        Deque<Integer> stack = new ArrayDeque<>();
8        for(String token : tokens){
9            boolean isValidNumber = isNumber(token);
10            if(isValidNumber || stack.isEmpty()){
11                stack.push(Integer.parseInt(token));
12            } else {
13                int a = stack.pop();
14                int b = stack.pop();
15
16                int evaluation = evaluate(b, a, token);
17                stack.push(evaluation);
18            }
19        }
20        return stack.peek();
21    }
22
23    private int evaluate(Integer a, Integer b, String operator){
24        switch (operator) {
25            case "+":
26                return a + b;
27            case "-":
28                return a - b;
29            case "*":
30                return a * b;
31            case "/":
32                return a / b;
33        }
34        return 0;
35    }
36
37
38    private boolean isNumber(String token){
39        if(token.length() == 0 || token == null)
40            return false;
41        try {
42            Integer.parseInt(token);
43            return true;
44        } catch (NumberFormatException e) {
45            return false;
46        }
47    }
48}