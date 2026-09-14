// Last updated: 9/14/2026, 11:04:37 AM
1import java.util.concurrent.Semaphore;
2
3class FooBar {
4    private int n;
5    public final Semaphore fooSemaphore = new Semaphore(1);
6    public final Semaphore barSemaphore = new Semaphore(0);
7
8
9    public FooBar(int n) {
10        this.n = n;
11    }
12
13    public void foo(Runnable printFoo) throws InterruptedException {
14
15        for (int i = 0; i < n; i++) {
16            fooSemaphore.acquire();
17            // printFoo.run() outputs "foo". Do not change or remove this line.
18            printFoo.run();
19            barSemaphore.release();
20        }
21    }
22
23    public void bar(Runnable printBar) throws InterruptedException {
24
25        for (int i = 0; i < n; i++) {
26            barSemaphore.acquire();
27            // printBar.run() outputs "bar". Do not change or remove this line.
28            printBar.run();
29            fooSemaphore.release();
30        }
31    }
32}