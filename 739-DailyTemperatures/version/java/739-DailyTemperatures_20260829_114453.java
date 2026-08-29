// Last updated: 8/29/2026, 11:44:53 AM
1import java.util.ArrayDeque;
2import java.util.Deque;
3
4class Solution {
5    public int[] dailyTemperatures(int[] temperatures) {
6        int size = temperatures.length;
7        int[] nextDay = new int[size];
8        Deque<Integer> stack = new ArrayDeque<>();
9        for(int i = size-1; i >= 0; i--){
10            int temperature = temperatures[i];
11            while(!stack.isEmpty() && temperatures[stack.peek()] <= temperature){
12                stack.pop();
13            }
14            if(stack.isEmpty()){
15                nextDay[i] = 0;
16            } else {
17                nextDay[i] = stack.peek()-i;
18            }
19            stack.push(i);
20        }
21        return nextDay;
22    }
23}