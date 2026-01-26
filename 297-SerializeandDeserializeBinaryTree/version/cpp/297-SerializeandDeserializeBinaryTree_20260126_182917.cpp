// Last updated: 1/26/2026, 6:29:17 PM
1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
8 * };
9 */
10class Codec {
11public:
12
13    string serializedTree;
14
15    // Encodes a tree to a single string.
16    string serialize(TreeNode* root) {
17        utils(root);
18        return serializedTree;
19    }
20
21    void utils(TreeNode* root){
22        if(root == nullptr){
23            serializedTree += "(#)";
24            return;
25        }
26        serializedTree += "(" + to_string(root->val) + ")";
27        serialize(root->left);
28        serialize(root->right);
29    }
30
31    // Decodes your encoded data to tree.
32    TreeNode* deserialize(string s) {
33        int idx = 0;
34        return build(s, idx);
35    }
36
37    TreeNode* build(const string &s, int &i) {
38        // Expect '('
39        i++;  // skip '('
40
41        // Null node
42        if (s[i] == '#') {
43            i += 2; // skip "#)"
44            return nullptr;
45        }
46
47        // Parse number (can be multi-digit, can be negative)
48        int sign = 1;
49        if (s[i] == '-') {
50            sign = -1;
51            i++;
52        }
53
54        int num = 0;
55        while (isdigit(s[i])) {
56            num = num * 10 + (s[i] - '0');
57            i++;
58        }
59        num *= sign;
60
61        i++; // skip ')'
62
63        TreeNode* node = new TreeNode(num);
64        node->left = build(s, i);
65        node->right = build(s, i);
66        return node;
67    }
68};
69
70// Your Codec object will be instantiated and called as such:
71// Codec ser, deser;
72// TreeNode* ans = deser.deserialize(ser.serialize(root));