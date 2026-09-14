// Last updated: 9/14/2026, 11:50:04 AM
1import java.util.concurrent.Semaphore;
2import java.util.function.IntConsumer;
3
4class FizzBuzz {
5    private int n;
6    int count = 1;
7    Semaphore numSem = new Semaphore(0);
8    Semaphore fizzSem = new Semaphore(0);
9    Semaphore buzzSem = new Semaphore(0);
10    Semaphore fizzBuzzSem = new Semaphore(0);
11
12    public FizzBuzz(int n) {
13        this.n = n;
14        computeSem(count).release();
15    }
16
17    // printFizz.run() outputs "fizz".
18    public void fizz(Runnable printFizz) throws InterruptedException {
19        while(count <= n) {
20            fizzSem.acquire();
21            if(count <= n)
22                printFizz.run();
23            count++;
24            computeSem(count).release();
25        }
26    }
27
28    // printBuzz.run() outputs "buzz".
29    public void buzz(Runnable printBuzz) throws InterruptedException {
30        while(count <= n) {
31            buzzSem.acquire();
32            if(count <= n)
33                printBuzz.run();
34            count++;
35            computeSem(count).release();
36        }
37    }
38
39    // printFizzBuzz.run() outputs "fizzbuzz".
40    public void fizzbuzz(Runnable printFizzBuzz) throws InterruptedException {
41        while(count <= n) {
42            fizzBuzzSem.acquire();
43            if(count <= n)
44                printFizzBuzz.run();
45            count++;
46            computeSem(count).release();
47        }
48    }
49
50    // printNumber.accept(x) outputs "x", where x is an integer.
51    public void number(IntConsumer printNumber) throws InterruptedException {
52        while(count <= n) {
53            numSem.acquire();
54            if(count <= n)
55            printNumber.accept(count);
56            count++;
57            computeSem(count).release();
58        }
59    }
60
61    public Semaphore computeSem(int count) {
62        if(count > n) {
63            numSem.release();
64            fizzSem.release();
65            buzzSem.release();
66            fizzBuzzSem.release();
67        }
68        if(count % 3 != 0 && count % 5 != 0)
69            return numSem;
70        else if(count % 3 == 0 && count % 5 == 0)
71            return fizzBuzzSem;
72        else if(count % 3 == 0)
73            return fizzSem;
74        return buzzSem;
75    }
76}