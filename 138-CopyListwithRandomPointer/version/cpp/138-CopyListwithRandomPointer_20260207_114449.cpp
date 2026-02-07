// Last updated: 2/7/2026, 11:44:49 AM
1/*
2// Definition for a Node.
3class Node {
4public:
5    int val;
6    Node* next;
7    Node* random;
8    
9    Node(int _val) {
10        val = _val;
11        next = NULL;
12        random = NULL;
13    }
14};
15*/
16
17class Solution {
18public:
19    Node* copyRandomList(Node* head) {
20        // traversal 1: To create a copy of all the nodes and store them in a map
21
22        // traversal 2: To connect the new nodes since we have a copy for each original node 
23
24        unordered_map<Node*, Node*> mp;
25        Node *temp = head;
26        while(temp != nullptr){
27            Node* copy = new Node(temp->val);
28            mp[temp] = copy;
29            temp = temp->next;
30        }
31        temp = head;
32        while(temp != nullptr){
33            Node *copy = mp[temp];
34            copy->next = mp[temp->next];
35            copy->random = mp[temp->random];
36            temp = temp->next;
37        }
38        return mp[head];
39    }
40};