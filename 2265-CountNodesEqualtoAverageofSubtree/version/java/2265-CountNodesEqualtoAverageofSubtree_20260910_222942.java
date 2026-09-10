// Last updated: 9/10/2026, 10:29:42 PM
1class Solution {
2    private int ans = 0;
3    public int averageOfSubtree(TreeNode root) {
4        int[] res = traversal(root);
5        return ans;
6    }
7
8    int[] traversal(TreeNode root) {
9        if(root == null){
10            return new int[]{0, 0};
11        }
12        int[] left = traversal(root.left);
13        int[] right = traversal(root.right);
14        int count = left[0] + right[0] + 1;
15        int sum  =left[1] + right[1] + root.val;
16        if(sum / count == root.val) ans++;
17        return new int[]{count, sum};
18    }
19}