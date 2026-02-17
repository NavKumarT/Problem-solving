// Last updated: 2/17/2026, 8:15:40 PM
1class Solution {
2    private: 
3    unordered_set<char> st;
4        
5public:
6    string reverseVowels(string s) {
7        string vowels = "aeiouAEIOU";
8        for(char n : vowels)
9            st.insert(n);
10        int n = s.length();
11        int start = 0, end = n-1;
12        while(start <= end){
13            while(start < end && isVowel(s[start]) == false)
14                start++;
15            while(start < end && isVowel(s[end]) == false)
16                end--;
17            swap(s[start++], s[end--]);
18        }
19        return s;
20    }
21
22    bool isVowel(char c){
23        
24        return st.find(c) != st.end();
25    }
26};