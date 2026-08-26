// Last updated: 8/26/2026, 11:05:35 AM
1import java.util.ArrayDeque;
2import java.util.Queue;
3
4class Solution {
5    public boolean isValid(String s) {
6        Deque<Character> stack = new ArrayDeque<>();
7        for(Character ch : s.toCharArray()){
8            if((ch == '(') || (ch == '{') || (ch == '[')){
9                stack.push(ch);
10            } else if(stack.isEmpty() || !isMatching(stack.peek(), ch)) {
11                return false;
12            }else if(isMatching(stack.peek(), ch)){
13                stack.pop();
14            }
15        }
16        return stack.isEmpty();
17    }
18
19    private boolean isMatching(char opening, char closing) {
20        return (opening == '(' && closing == ')') ||
21                (opening == '{' && closing == '}') ||
22                (opening == '[' && closing == ']');
23    }
24
25}