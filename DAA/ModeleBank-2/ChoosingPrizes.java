import java.util.*;

// -----------------------
// Common Prize class
// -----------------------
class Prize {
    int value;
    // For part (b): type is given as a char: 'A' or 'B'.
    // For parts (a) and (c) type is irrelevant.
    char type;

    public Prize(int value) {
        this.value = value;
        this.type = 'X'; // dummy type for parts (a) and (c)
    }

    public Prize(int value, char type) {
        this.value = value;
        this.type = type;
    }

    @Override
    public String toString() {
        return "Prize(value=" + value + (type=='X' ? "" : ", type=" + type) + ")";
    }
}

// -----------------------
// (a) Subsequence of at most m prizes (order preserved)
// -----------------------
class ChoosingPrizesA {

    // Returns maximum total value and the chosen subsequence (order preserved)
    // using up to m prizes from sequence P.
    // Time: O(n*m), Space: O(n*m)
    public static Result choosePrizes(List<Prize> P, int m) {
        int n = P.size();
        // dp[i][j] = maximum total value using first i prizes with exactly j chosen.
        int[][] dp = new int[n + 1][m + 1];
        // To reconstruct the solution, use a choice table.
        boolean[][] take = new boolean[n + 1][m + 1];

        // Initialize: dp[0][j] = 0 for all j.
        for (int i = 0; i <= n; i++) {
            Arrays.fill(dp[i], 0);
        }

        // DP: consider prizes 1..n (1-indexed in dp, 0-indexed in list)
        for (int i = 1; i <= n; i++) {
            Prize p = P.get(i - 1);
            for (int j = 0; j <= m; j++) {
                // Option 1: Skip prize i.
                dp[i][j] = dp[i - 1][j];
                // Option 2: Take prize i if j >= 1.
                if (j > 0 && dp[i - 1][j - 1] + p.value > dp[i][j]) {
                    dp[i][j] = dp[i - 1][j - 1] + p.value;
                    take[i][j] = true;
                }
            }
        }

        // Find best answer among j = 0..m
        int bestVal = 0, bestCount = 0;
        for (int j = 0; j <= m; j++) {
            if (dp[n][j] > bestVal) {
                bestVal = dp[n][j];
                bestCount = j;
            }
        }

        // Reconstruct the subsequence (backtracking)
        List<Prize> chosen = new ArrayList<>();
        int i = n, j = bestCount;
        while (i > 0 && j >= 0) {
            if (take[i][j]) {
                chosen.add(P.get(i - 1));
                j--;
            }
            i--;
        }
        // The chosen items are in reverse order; reverse them.
        Collections.reverse(chosen);

        return new Result(bestVal, chosen);
    }
}

// -----------------------
// (b) Two Types with constraint: all A’s must precede B’s.
// -----------------------
class ChoosingPrizesB {

    // DP state: dp[i][j][b] = maximum value using first i prizes, exactly j chosen, with state b.
    // b = 0: haven’t taken any type B yet (only A's allowed).
    // b = 1: already started taking type B.
    // Returns maximum total value and (optionally) the reconstruction.
    // Time: O(n*m*2), Space: O(n*m*2)
    public static Result choosePrizes(List<Prize> P, int m) {
        int n = P.size();
        // Use -infinity for impossible states.
        int NEG_INF = -1000000000;
        int[][][] dp = new int[n + 1][m + 1][2];
        boolean[][][] take = new boolean[n + 1][m + 1][2]; // record if we take prize i in that state
        int[][][] fromState = new int[n + 1][m + 1][2]; // to record previous b value (for backtracking)

        // Initialize dp[0][0][0] = 0, and others = -infinity.
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                Arrays.fill(dp[i][j], NEG_INF);
            }
        }
        dp[0][0][0] = 0;

        // Process items 1..n
        for (int i = 1; i <= n; i++) {
            Prize p = P.get(i - 1);
            for (int j = 0; j <= m; j++) {
                for (int b = 0; b < 2; b++) {
                    // Option: skip prize i.
                    if (dp[i - 1][j][b] > dp[i][j][b]) {
                        dp[i][j][b] = dp[i - 1][j][b];
                        // No change in state; record that we did not take this prize.
                        // (For simplicity, we omit detailed reconstruction info.)
                    }
                    // Option: take prize i if j < m.
                    if (j < m) {
                        // If prize is type A:
                        if (p.type == 'A') {
                            // Can only take if b == 0.
                            if (b == 0 && dp[i - 1][j][0] + p.value > dp[i][j + 1][0]) {
                                dp[i][j + 1][0] = dp[i - 1][j][0] + p.value;
                                take[i][j + 1][0] = true;
                                fromState[i][j + 1][0] = b;
                            }
                        }
                        // If prize is type B:
                        if (p.type == 'B') {
                            // If b == 0, taking this prize will start the B block (transition to state 1).
                            if (b == 0 && dp[i - 1][j][0] + p.value > dp[i][j + 1][1]) {
                                dp[i][j + 1][1] = dp[i - 1][j][0] + p.value;
                                take[i][j + 1][1] = true;
                                fromState[i][j + 1][1] = b;
                            }
                            // If already in B mode (b == 1), we can take another B.
                            if (b == 1 && dp[i - 1][j][1] + p.value > dp[i][j + 1][1]) {
                                dp[i][j + 1][1] = dp[i - 1][j][1] + p.value;
                                take[i][j + 1][1] = true;
                                fromState[i][j + 1][1] = b;
                            }
                        }
                    }
                }
            }
        }

        // Find best answer among dp[n][j][b] for j <= m and b = 0,1.
        int bestVal = NEG_INF, bestJ = 0, bestB = 0;
        for (int j = 0; j <= m; j++) {
            for (int b = 0; b < 2; b++) {
                if (dp[n][j][b] > bestVal) {
                    bestVal = dp[n][j][b];
                    bestJ = j;
                    bestB = b;
                }
            }
        }
        // (Reconstruction is omitted here for brevity.)
        return new Result(bestVal, null);
    }
}

// -----------------------
// (c) Subsequence with non-decreasing prize values.
// -----------------------
class ChoosingPrizesC {

    // We want a subsequence (order preserved) of at most m prizes
    // whose values are non-decreasing.
    // We use a DP formulation where for each prize i (1-indexed) and number chosen j,
    // dp[i][j] is the maximum total value obtainable from a non-decreasing subsequence that ends at prize i.
    // We then take the best over all possible endings.
    // Time: O(n^2 * m), Space: O(n*m)
    public static Result choosePrizes(List<Prize> P, int m) {
        int n = P.size();
        // dp[i][j]: best total value for a subsequence ending at index i (0-indexed) using exactly j items.
        // We use -infinity for impossible states.
        int NEG_INF = -1000000000;
        int[][] dp = new int[n][m + 1];
        // Initialize dp: for j = 1, dp[i][1] = P[i].value.
        for (int i = 0; i < n; i++) {
            dp[i][1] = P.get(i).value;
            for (int j = 2; j <= m; j++) {
                dp[i][j] = NEG_INF;
            }
        }
        int bestVal = 0;
        // For each prize i as a candidate for the end of a subsequence of length j.
        for (int i = 0; i < n; i++) {
            for (int j = 2; j <= m; j++) {
                // Look for a previous prize k with k < i and P[k].value <= P[i].value.
                for (int k = 0; k < i; k++) {
                    if (P.get(k).value <= P.get(i).value && dp[k][j - 1] != NEG_INF) {
                        dp[i][j] = Math.max(dp[i][j], dp[k][j - 1] + P.get(i).value);
                    }
                }
            }
            // Update best answer over all lengths.
            for (int j = 1; j <= m; j++) {
                bestVal = Math.max(bestVal, dp[i][j]);
            }
        }
        // (Reconstruction is more involved and is omitted for brevity.)
        return new Result(bestVal, null);
    }
}

// -----------------------
// (d) Tree–structured prizes (connected subtree rooted at r)
// -----------------------
class TreeNode {
    int value;
    TreeNode left;
    TreeNode right;
    // For identification (optional)
    int id;

    public TreeNode(int id, int value) {
        this.id = id;
        this.value = value;
    }
}

class ChoosingPrizesD {

    // For each node u, let dp[u][j] = maximum total value obtainable from a connected subtree
    // of the subtree rooted at u that includes u and uses exactly j nodes.
    // We assume m is the overall limit.
    // Time: O(n*m^2) overall.
    public static Map<TreeNode, int[]> dpTree(TreeNode root, int m) {
        // returns a mapping from node to an int array dp[0..m]
        // dp[j] = maximum sum using j nodes from the subtree rooted at that node (including the node itself)
        Map<TreeNode, int[]> dpMap = new HashMap<>();
        dfs(root, m, dpMap);
        return dpMap;
    }

    private static void dfs(TreeNode u, int m, Map<TreeNode, int[]> dpMap) {
        int[] dp = new int[m + 1];
        // Initialize: if we use exactly 1 node (just u), value = u.value; for more nodes, initialize to -infinity.
        int NEG_INF = -1000000000;
        dp[1] = u.value;
        for (int j = 2; j <= m; j++) {
            dp[j] = NEG_INF;
        }
        // Process left and right children and merge.
        if (u.left != null) {
            dfs(u.left, m, dpMap);
            int[] leftDP = dpMap.get(u.left);
            // Merge u and left subtree:
            // For each split: use i nodes from current dp and j nodes from left such that i + j <= m.
            int[] newDP = new int[m + 1];
            Arrays.fill(newDP, NEG_INF);
            for (int i = 1; i <= m; i++) {
                if (dp[i] == NEG_INF) continue;
                // Option: do not take any nodes from left.
                newDP[i] = Math.max(newDP[i], dp[i]);
                for (int j = 1; i + j <= m; j++) {
                    if (leftDP[j] != NEG_INF) {
                        newDP[i + j] = Math.max(newDP[i + j], dp[i] + leftDP[j]);
                    }
                }
            }
            dp = newDP;
        }
        if (u.right != null) {
            dfs(u.right, m, dpMap);
            int[] rightDP = dpMap.get(u.right);
            int[] newDP = new int[m + 1];
            Arrays.fill(newDP, NEG_INF);
            for (int i = 1; i <= m; i++) {
                if (dp[i] == NEG_INF) continue;
                newDP[i] = Math.max(newDP[i], dp[i]);
                for (int j = 1; i + j <= m; j++) {
                    if (rightDP[j] != NEG_INF) {
                        newDP[i + j] = Math.max(newDP[i + j], dp[i] + rightDP[j]);
                    }
                }
            }
            dp = newDP;
        }
        dpMap.put(u, dp);
    }

    // The overall answer is max_{j <= m} dp[r][j], where r is the root.
    public static int bestTreePrize(TreeNode root, int m) {
        Map<TreeNode, int[]> dpMap = dpTree(root, m);
        int[] dpRoot = dpMap.get(root);
        int best = 0;
        for (int j = 1; j <= m; j++) {
            best = Math.max(best, dpRoot[j]);
        }
        return best;
    }
}

// -----------------------
// Helper class to encapsulate a result.
class Result {
    int totalValue;
    List<Prize> selectedPrizes;  // may be null if reconstruction is omitted

    public Result(int totalValue, List<Prize> selectedPrizes) {
        this.totalValue = totalValue;
        this.selectedPrizes = selectedPrizes;
    }
}

// -----------------------
// Main class: Demonstrate usage
// -----------------------
public class ChoosingPrizes {

    public static void main(String[] args) {
        // Part (a): Unconstrained order–preserving subsequence
        System.out.println("=== Part (a): Unconstrained Subsequence ===");
        List<Prize> prizesA = Arrays.asList(
            new Prize(10),
            new Prize(5),
            new Prize(12),
            new Prize(7),
            new Prize(8)
        );
        int mA = 3;
        Result resA = ChoosingPrizesA.choosePrizes(prizesA, mA);
        System.out.println("Max total value: " + resA.totalValue);
        System.out.println("Selected prizes: " + resA.selectedPrizes);

        // Part (b): Two types with constraint: all A's must come before B's.
        System.out.println("\n=== Part (b): Two Types (A then B) ===");
        List<Prize> prizesB = Arrays.asList(
            new Prize(10, 'A'),
            new Prize(5, 'B'),
            new Prize(12, 'A'),
            new Prize(7, 'B'),
            new Prize(8, 'B'),
            new Prize(9, 'A')  // note: if an A comes after a B, it should not be allowed.
        );
        int mB = 4;
        // Using the DP that tracks state.
        Result resB = ChoosingPrizesB.choosePrizes(prizesB, mB);
        System.out.println("Max total value (with A->B constraint): " + resB.totalValue);
        // Reconstruction is omitted for brevity.

        // Part (c): Non-decreasing sequence of values.
        System.out.println("\n=== Part (c): Non-decreasing Values ===");
        List<Prize> prizesC = Arrays.asList(
            new Prize(3),
            new Prize(7),
            new Prize(5),
            new Prize(8),
            new Prize(9),
            new Prize(6)
        );
        int mC = 4;
        Result resC = ChoosingPrizesC.choosePrizes(prizesC, mC);
        System.out.println("Max total value (non-decreasing): " + resC.totalValue);

        // Part (d): Tree–structured prizes.
        System.out.println("\n=== Part (d): Tree–Structured Prizes ===");
        // Build a sample tree.
        TreeNode root = new TreeNode(1, 10);
        root.left = new TreeNode(2, 5);
        root.right = new TreeNode(3, 15);
        root.left.left = new TreeNode(4, 20);
        root.left.right = new TreeNode(5, 1);
        root.right.left = new TreeNode(6, 2);
        root.right.right = new TreeNode(7, 30);
        int mD = 4;
        int bestTreeValue = ChoosingPrizesD.bestTreePrize(root, mD);
        System.out.println("Max total value from tree (connected subtree with at most " + mD + " nodes): " + bestTreeValue);
    }
}
