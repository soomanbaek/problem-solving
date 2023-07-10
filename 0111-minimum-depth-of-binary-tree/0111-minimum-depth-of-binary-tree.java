/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

class Node{
    TreeNode node;
    int depth;

    Node(TreeNode node, int depth){
        this.node = node;
        this.depth = depth;
    }
}

class Solution {
    public int minDepth(TreeNode root) {
        Queue<Node> Q = new LinkedList<Node>();
        Q.add(new Node(root, 1));
        int answer = 0;
        if(root == null)    return 0;

        while(!Q.isEmpty()){
            Node cur = Q.poll();
            TreeNode curNode = cur.node;
            if(curNode.left == null && curNode.right == null){
                answer = cur.depth;
                break;
            }
            if(curNode.left != null){
                Q.add(new Node(curNode.left, cur.depth + 1));
            }
            if(curNode.right != null){
                Q.add(new Node(curNode.right, cur.depth + 1));
            }
        }
        return answer;
    }
}