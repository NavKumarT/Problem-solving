// Last updated: 8/13/2026, 10:52:51 AM
1
2
3/**
4 * Definition for a binary tree node.
5 * public class TreeNode {
6 *     int val;
7 *     TreeNode left;
8 *     TreeNode right;
9 *     TreeNode() {}
10 *     TreeNode(int val) { this.val = val; }
11 *     TreeNode(int val, TreeNode left, TreeNode right) {
12 *         this.val = val;
13 *         this.left = left;
14 *         this.right = right;
15 *     }
16 * }
17 */
18class Solution {
19    public List<Integer> preorderTraversal(TreeNode root) {
20        List<Integer> traversal = new ArrayList<>();
21        traversal(root, traversal);
22        return traversal;
23    }
24
25    public void traversal(TreeNode root, List<Integer> traversal){
26        if(root == null)
27            return;
28        traversal.add(root.val);
29        traversal(root.left, traversal);
30        traversal(root.right, traversal);
31    }
32}