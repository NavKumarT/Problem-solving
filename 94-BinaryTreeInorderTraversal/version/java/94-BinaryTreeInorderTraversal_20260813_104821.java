// Last updated: 8/13/2026, 10:48:21 AM
1/**
2 * Definition for a binary tree node.
3 * public class TreeNode {
4 *     int val;
5 *     TreeNode left;
6 *     TreeNode right;
7 *     TreeNode() {}
8 *     TreeNode(int val) { this.val = val; }
9 *     TreeNode(int val, TreeNode left, TreeNode right) {
10 *         this.val = val;
11 *         this.left = left;
12 *         this.right = right;
13 *     }
14 * }
15 */
16class Solution {
17    public List<Integer> inorderTraversal(TreeNode root) {
18        List<Integer> traversal = new ArrayList<>();
19        traversal(root, traversal);
20        return traversal;
21    }
22
23    public void traversal(TreeNode root, List<Integer> traversal){
24        if(root == null)
25            return;
26        traversal(root.left, traversal);
27        traversal.add(root.val);
28        traversal(root.right, traversal);
29    }
30}