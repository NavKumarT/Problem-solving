// Last updated: 6/28/2026, 9:22:21 PM
1class Solution {
2public:
3    string reorganizeString(string s) {
4        unordered_map<char, int> hashMap;
5        for(char &ch : s){
6            hashMap[ch]++;
7        }
8
9        priority_queue<pair<int, char>> maxHeap;
10
11        for(auto it : hashMap){
12            maxHeap.push({it.second, it.first});
13        }
14
15        string ans = "";
16
17        while(!maxHeap.empty()){
18            pair<int, char> a = maxHeap.top();
19            maxHeap.pop();
20            ans += a.second;
21            a.first--;
22            if(maxHeap.empty() && ans.length() != s.length())
23                return "";
24            else if(ans.length() == s.length())
25                return ans;
26            pair<int, char> b = maxHeap.top();
27            maxHeap.pop();
28            ans += b.second;
29            b.first--;
30            if(a.first > 0)
31            maxHeap.push(a);
32            if(b.first>0)
33                maxHeap.push(b);
34            }
35        return ans;
36    }
37};