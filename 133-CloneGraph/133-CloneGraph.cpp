// Last updated: 8/29/2025, 9:52:16 PM
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr)
            return nullptr;
        unordered_map<Node*, Node*> mp;
        unordered_set<Node*> s;
        s.insert(node);
        queue<Node*> q;
        q.push(node);
        // STEP 1 : create duplicates of all nodes as you do bfs 
        while(q.empty() == false){
            Node *n = q.front(); q.pop();
            Node* temp = new Node(n->val);
            mp[n] = temp;
            for(Node* neighbor : n->neighbors){
                if(s.find(neighbor) == s.end()){
                    s.insert(neighbor);
                    q.push(neighbor);
                }
            }
        }
        s.clear();
        s.insert(node);
        q.push(node);
        // STEP 2: While doing a second BFS, create the neighbors array made of duplicates and add them to the 
        // duplicates' neighbors.
        while(q.empty() == false){
            Node *n = q.front(); q.pop();
            Node* temp = mp[n];
            vector<Node*> arr;
            for(Node* neighbor : n->neighbors){
                if(s.find(neighbor) == s.end()){
                    s.insert(neighbor);
                    q.push(neighbor);
                }
                // add to the list of neighbors regardless of if they have been visited 
                arr.push_back(mp[neighbor]);
            }
            temp->neighbors = arr;
        }
        return mp[node];
    }
};