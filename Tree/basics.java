package Tree;

import java.util.*;

public class basics {

    public static class Node {
        int val = 0;
        Node left = null;
        Node right = null;

        Node(int val) {
            this.val = val;
        }
    }

    public static boolean NodetoRootpath(Node node, int data, ArrayList<Node> ans) {
        if (node == null)
            return false;

        if (node.val == data) {
            ans.add(node);
            return true;
        }
        boolean res = NodetoRootpath(node.left, data, ans) || NodetoRootpath(node.right, data, ans);

        if (res)
            ans.add(node);

        return res;

    }

    public static void main(String args[]) {

    }
}