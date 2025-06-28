public class ReliabilityDesignDP {

    // Computes φ_i(m) = 1 - (1 - r)^m
    public static double phi(double r, int m) {
        return 1 - Math.pow(1 - r, m);
    }

    // DP algorithm to compute the best reliability given resource X
    // n: number of device types
    // c: cost array for each device type (indexed from 0 to n-1)
    // r: reliability array for each device type (indexed from 0 to n-1)
    public static double solveReliability(int X, int n, int[] c, double[] r) {
        // F[x] will store the best reliability achievable with resource x.
        double[] F = new double[X + 1];
        // Initialize F[0] = 0 and the rest to a very small number.
        F[0] = 0;
        for (int x = 1; x <= X; x++) {
            F[x] = Double.NEGATIVE_INFINITY;
        }

        // For each resource level from 1 to X
        for (int x = 1; x <= X; x++) {
            // Consider each device type i
            for (int i = 0; i < n; i++) {
                // Determine the maximum number of copies we can afford of device i
                int maxCopies = x / c[i];
                for (int m = 1; m <= maxCopies; m++) {
                    int costUsed = m * c[i];
                    double candidate = phi(r[i], m) + F[x - costUsed];
                    if (candidate > F[x]) {
                        F[x] = candidate;
                    }
                }
            }
        }
        return F[X];
    }

    public static void main(String[] args) {
        // Example parameters:
        // Suppose we have 3 device types.
        int n = 3;
        // Costs per copy for each device type (e.g., cost in dollars)
        int[] c = { 2, 3, 5 }; // for example, device 1 costs 2 units, device 2 costs 3 units, etc.
        // Reliability for each device type (probability of working)
        double[] r = { 0.99, 0.98, 0.97 };

        // Total available resource (budget)
        int X = 20;

        double bestReliability = solveReliability(X, n, c, r);
        System.out.println("Best achievable reliability (in additive terms): " + bestReliability);
    }
}
