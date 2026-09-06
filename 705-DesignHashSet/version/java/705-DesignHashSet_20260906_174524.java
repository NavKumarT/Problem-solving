// Last updated: 9/6/2026, 5:45:24 PM
1import java.lang.reflect.Array;
2import java.util.ArrayList;
3
4class MyHashSet {
5
6    ArrayList<ArrayList<Integer>> container = new ArrayList<>(10);
7    public MyHashSet() {
8        for (int i = 0; i < 10; i++) {
9            container.add(new ArrayList<>());
10        }
11    }
12
13    public void add(int key) {
14        container.get(key % 10).add(key);
15    }
16
17
18    public void remove(int key) {
19        container.get(key % 10).removeIf(n -> n == key);
20    }
21
22    public boolean contains(int key) {
23        ArrayList<Integer> arr = container.get(key % 10);
24        for(Integer num : arr) {
25            if(num == key)
26                return true;
27        }
28        return false;
29    }
30}
31
32/**
33 * Your MyHashSet object will be instantiated and called as such:
34 * MyHashSet obj = new MyHashSet();
35 * obj.add(key);
36 * obj.remove(key);
37 * boolean param_3 = obj.contains(key);
38 */