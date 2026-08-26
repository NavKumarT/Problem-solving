// Last updated: 8/26/2026, 10:32:38 AM
1import java.util.*;
2
3class Task {
4    int enqueueTime;
5    int processingTime;
6    int index;
7
8    Task(int eT, int pT, int idx) {
9        this.enqueueTime = eT;
10        this.processingTime = pT;
11        this.index = idx;
12    }
13}
14
15class Solution {
16    public int[] getOrder(int[][] tasks) {
17        int n = tasks.length;
18
19        // Add original index
20        for (int i = 0; i < n; i++) {
21            tasks[i] = Arrays.copyOf(tasks[i], 3);
22            tasks[i][2] = i;
23        }
24
25        // Sort by enqueue time
26        Arrays.sort(tasks, (a, b) -> Integer.compare(a[0], b[0]));
27
28        // Min heap:
29        // 1. Smaller processing time
30        // 2. Smaller original index
31        PriorityQueue<Task> minHeap = new PriorityQueue<>((a, b) -> {
32            if (a.processingTime != b.processingTime) {
33                return Integer.compare(a.processingTime, b.processingTime);
34            }
35            return Integer.compare(a.index, b.index);
36        });
37
38        int pointer = 0;
39        long currentTime = 0;
40
41        int[] order = new int[n];
42        int resultIndex = 0;
43
44        while (pointer < n || !minHeap.isEmpty()) {
45
46            // CPU is idle, jump to the next task's enqueue time
47            if (minHeap.isEmpty()) {
48                currentTime = Math.max(currentTime, tasks[pointer][0]);
49            }
50
51            // Add all tasks that have arrived
52            while (pointer < n && tasks[pointer][0] <= currentTime) {
53                minHeap.offer(new Task(
54                    tasks[pointer][0],
55                    tasks[pointer][1],
56                    tasks[pointer][2]
57                ));
58                pointer++;
59            }
60
61            // Process the task with smallest processing time
62            Task task = minHeap.poll();
63
64            order[resultIndex++] = task.index;
65            currentTime += task.processingTime;
66        }
67
68        return order;
69    }
70}