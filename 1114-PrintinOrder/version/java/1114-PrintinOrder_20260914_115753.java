// Last updated: 9/14/2026, 11:57:53 AM
1import java.util.concurrent.Semaphore;
2
3class Foo {
4
5    Semaphore s1 =  new Semaphore(1);
6    Semaphore s2 = new Semaphore(0);
7    Semaphore s3 = new Semaphore(0);
8
9    public Foo() {
10
11    }
12
13    public void first(Runnable printFirst) throws InterruptedException {
14s1.acquire();
15        // printFirst.run() outputs "first". Do not change or remove this line.
16        printFirst.run();
17        s2.release();
18    }
19
20    public void second(Runnable printSecond) throws InterruptedException {
21s2.acquire();
22        // printSecond.run() outputs "second". Do not change or remove this line.
23        printSecond.run();
24        s3.release();
25    }
26
27    public void third(Runnable printThird) throws InterruptedException {
28s3.acquire();
29        // printThird.run() outputs "third". Do not change or remove this line.
30        printThird.run();
31        s1.release();
32    }
33}