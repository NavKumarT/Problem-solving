// Last updated: 8/29/2026, 10:38:01 AM
1import java.util.ArrayDeque;
2import java.util.Deque;
3import java.util.PriorityQueue;
4
5class Solution {
6    public int[] asteroidCollision(int[] asteroids) {
7        int numAsteroids = asteroids.length;
8        Deque<Integer> stack = new ArrayDeque<>();
9        for(int i = 0; i < numAsteroids; i++){
10            // check if the previous asteroid and the current one are 
11            // moving in the opposite direction to guarantee a collision
12            boolean isIncomingAsteroidDestroyed = false;
13            while(!stack.isEmpty() && stack.peek() > 0 && asteroids[i] < 0){
14                // if the current asteroid is larger, then it destroys the previous one 
15                int left = stack.peek();
16                int right = Math.abs(asteroids[i]);
17                if(right > left){
18                    // The asteroid on the right is destroyed
19                    stack.pop();
20                } else if(left > right){
21                    isIncomingAsteroidDestroyed = true;
22                    break;
23                } else {
24                    stack.pop();
25                    isIncomingAsteroidDestroyed = true;
26                    break;
27                }
28            }
29            if(!isIncomingAsteroidDestroyed)
30                stack.push(asteroids[i]);
31            
32            // stack: 5 10 
33        }  
34        int[] finalAsteroidOrder = new int[stack.size()];
35        int idx = stack.size()-1;
36        while(!stack.isEmpty()){
37            finalAsteroidOrder[idx] = stack.peek();
38            stack.pop();
39            idx--;
40
41        }
42        return finalAsteroidOrder;
43    }
44}
45