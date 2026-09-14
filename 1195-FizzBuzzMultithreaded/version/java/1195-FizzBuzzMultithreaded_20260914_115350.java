// Last updated: 9/14/2026, 11:53:50 AM
1import java.util.concurrent.Semaphore;
2import java.util.function.IntConsumer;
3
4class FizzBuzz {
5    private int n;
6    private Semaphore numSem = new Semaphore(1);
7    private Semaphore fizzSem = new Semaphore(0);
8    private Semaphore buzzSem = new Semaphore(0);
9    private Semaphore fizzBuzzSem = new Semaphore(0);
10
11    public FizzBuzz(int n) {
12        this.n = n;
13    }
14
15    public void fizz(Runnable printFizz) throws InterruptedException {
16        for (int i = 3; i <= n; i += 3) {
17            if (i % 5 != 0) { // Multiples of 3 only (not 15)
18                fizzSem.acquire();
19                printFizz.run();
20                numSem.release();
21            }
22        }
23    }
24
25    public void buzz(Runnable printBuzz) throws InterruptedException {
26        for (int i = 5; i <= n; i += 5) {
27            if (i % 3 != 0) { // Multiples of 5 only (not 15)
28                buzzSem.acquire();
29                printBuzz.run();
30                numSem.release();
31            }
32        }
33    }
34
35    public void fizzbuzz(Runnable printFizzBuzz) throws InterruptedException {
36        for (int i = 15; i <= n; i += 15) {
37            fizzBuzzSem.acquire();
38            printFizzBuzz.run();
39            numSem.release();
40        }
41    }
42
43    public void number(IntConsumer printNumber) throws InterruptedException {
44        for (int i = 1; i <= n; i++) {
45            numSem.acquire();
46            if (i % 15 == 0) {
47                fizzBuzzSem.release();
48            } else if (i % 3 == 0) {
49                fizzSem.release();
50            } else if (i % 5 == 0) {
51                buzzSem.release();
52            } else {
53                printNumber.accept(i);
54                numSem.release(); // Self-release if it's just a regular number
55            }
56        }
57    }
58}