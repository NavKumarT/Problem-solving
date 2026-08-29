// Last updated: 8/29/2026, 12:19:30 PM
1import java.util.ArrayDeque;
2import java.util.Deque;
3
4class Solution {
5    public String decodeString(String s) {
6        Deque<Character> stack = new ArrayDeque<>();
7        StringBuilder ans = new StringBuilder();
8        for(Character ch : s.toCharArray()){
9            StringBuilder temp = new StringBuilder();
10            if(ch != ']'){
11                stack.push(ch);
12            } else {
13                while(!stack.isEmpty() && stack.peek() != '['){
14                    temp.append(stack.peek());
15                    stack.pop();
16                }
17                stack.pop();
18                StringBuilder number = new StringBuilder();
19                while(!stack.isEmpty() && Character.isDigit(stack.peek())){
20                    number.append(stack.peek());
21                    stack.pop();
22                }
23                Integer numberValue = Integer.parseInt(number.reverse().toString());
24                temp = temp.reverse();
25                while(numberValue > 0){
26                    for(Character character : temp.toString().toCharArray())
27                        stack.push(character);
28                    numberValue--;
29                }
30            }
31        }
32        while(!stack.isEmpty()){
33            ans.append(stack.peek());
34            stack.pop();
35        }
36        return ans.reverse().toString();
37    }
38}