// Last updated: 9/14/2026, 11:20:18 AM
1import java.util.concurrent.Semaphore;
2import java.util.function.IntConsumer;
3
4class ZeroEvenOdd {
5    private int n;
6    private final Semaphore zeroSemaphore = new Semaphore(1);
7    private final Semaphore oddSemaphore = new Semaphore(0);
8    private final Semaphore evenSemaphore = new Semaphore(0);
9
10    public ZeroEvenOdd(int n) {
11        this.n = n;
12    }
13
14    public void zero(IntConsumer printNumber) throws InterruptedException {
15        for (int i = 1; i <= n; i++) {
16            zeroSemaphore.acquire();
17            printNumber.accept(0);
18            
19            // Route execution to odd or even based on the current number i
20            if (i % 2 != 0) {
21                oddSemaphore.release();
22            } else {
23                evenSemaphore.release();
24            }
25        }
26    }
27
28    public void even(IntConsumer printNumber) throws InterruptedException {
29        for (int i = 2; i <= n; i += 2) {
30            evenSemaphore.acquire();
31            printNumber.accept(i);
32            zeroSemaphore.release();
33        }
34    }
35
36    public void odd(IntConsumer printNumber) throws InterruptedException {
37        for (int i = 1; i <= n; i += 2) {
38            oddSemaphore.acquire();
39            printNumber.accept(i);
40            zeroSemaphore.release();
41        }
42    }
43}