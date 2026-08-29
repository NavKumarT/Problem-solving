// Last updated: 8/29/2026, 10:55:38 AM
1import java.util.ArrayDeque;
2import java.util.Deque;
3import java.util.Stack;
4
5class MinStack {
6    
7    Deque<StackNode> stack = new ArrayDeque<>();
8
9    public MinStack() {
10        
11    }
12
13    public void push(int value) {
14        if(stack.isEmpty()){
15            stack.push(new StackNode(value, value));
16        } else {
17            int minValue = Math.min(value, stack.peek().minValue);
18            stack.push(new StackNode(value, minValue));
19        }
20    }
21
22    public void pop() {
23        stack.pop();
24    }
25
26    public int top() {
27        return stack.peek().value;
28    }
29
30    public int getMin() {
31        return stack.peek().minValue;
32    }
33}
34
35class StackNode {
36    int value;
37    int minValue;
38    StackNode(int value, int minValue){
39        this.value = value;
40        this.minValue = minValue;
41    }
42}
43
44/**
45 * Your MinStack object will be instantiated and called as such:
46 * MinStack obj = new MinStack();
47 * obj.push(value);
48 * obj.pop();
49 * int param_3 = obj.top();
50 * int param_4 = obj.getMin();
51 */