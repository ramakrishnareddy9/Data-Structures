class TreeNode {
    int weight;
    TreeNode left, right;

    public TreeNode(int weight) {
        this.weight = weight;
        this.left = null;
        this.right = null;
    }
}

public class MaxWeightIndependentSet {

    private int[] getMaxWeight(TreeNode root) {
        if (root == null) {
            return new int[] { 0, 0 };
        }

        int[] left = getMaxWeight(root.left);
        int[] right = getMaxWeight(root.right);

        int includeRoot = root.weight + left[1] + right[1];
        int excludeRoot = Math.max(left[0], left[1]) + Math.max(right[0], right[1]);

        return new int[] { includeRoot, excludeRoot };
    }

    public int getMaxWeightIndependentSet(TreeNode root) {
        int[] result = getMaxWeight(root);
        return Math.max(result[0], result[1]);
    }

    public static void main(String[] args) {
        TreeNode root = new TreeNode(10);
        root.left = new TreeNode(5);
        root.right = new TreeNode(20);
        root.left.left = new TreeNode(1);
        root.left.right = new TreeNode(3);
        root.right.left = new TreeNode(4);
        root.right.right = new TreeNode(25);

        MaxWeightIndependentSet mwis = new MaxWeightIndependentSet();
        int maxWeight = mwis.getMaxWeightIndependentSet(root);

        System.out.println("Maximum Weight of Independent Set: " + maxWeight);
    }
}
