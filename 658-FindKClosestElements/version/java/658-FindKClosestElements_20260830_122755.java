// Last updated: 8/30/2026, 12:27:55 PM
1import java.util.*;
2
3class Solution {
4    public List<Integer> findClosestElements(int[] arr, int k, int x) {
5
6        // Max heap: worst candidate stays on top
7        Queue<HeapNode> maxHeap = new PriorityQueue<>((a, b) -> {
8            if (a.difference != b.difference) {
9                return Integer.compare(b.difference, a.difference);
10            }
11
12            // If equally distant, larger value is worse
13            return Integer.compare(b.value, a.value);
14        });
15
16        for (int num : arr) {
17            int difference = Math.abs(num - x);
18
19            if (maxHeap.size() < k) {
20                maxHeap.offer(new HeapNode(num, difference));
21                continue;
22            }
23
24            HeapNode worst = maxHeap.peek();
25
26            if (difference < worst.difference ||
27                    (difference == worst.difference && num < worst.value)) {
28
29                maxHeap.poll();
30                maxHeap.offer(new HeapNode(num, difference));
31            }
32        }
33
34        int[] result = new int[k];
35        int index = 0;
36
37        while (!maxHeap.isEmpty()) {
38            result[index++] = maxHeap.poll().value;
39        }
40
41        Arrays.sort(result);
42
43        return Arrays.stream(result)
44                .boxed()
45                .toList();
46    }
47}
48
49class HeapNode {
50    int value;
51    int difference;
52
53    HeapNode(int value, int difference) {
54        this.value = value;
55        this.difference = difference;
56    }
57}