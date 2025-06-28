import java.util.Arrays;
import java.util.Comparator;

public class KnapsackComparison {

    static class Item {
        double valuePerWeight;
        int value;
        int weight;
        int index;

        public Item(double valuePerWeight, int value, int weight, int index) {
            this.valuePerWeight = valuePerWeight;
            this.value = value;
            this.weight = weight;
            this.index = index;
        }
    }

    public static int knapsack01(int n, int W, int[] values, int[] weights) {
        int[][] dp = new int[n + 1][W + 1];

        for (int i = 1; i <= n; i++) {
            for (int w = 0; w <= W; w++) {
                if (weights[i - 1] <= w) {
                    dp[i][w] = Math.max(dp[i - 1][w], values[i - 1] + dp[i - 1][w - weights[i - 1]]);
                } else {
                    dp[i][w] = dp[i - 1][w];
                }
            }
        }

        return dp[n][W];
    }

    public static int greedySteal(int n, int W, int[] values, int[] weights) {
        Item[] items = new Item[n];
        for (int i = 0; i < n; i++) {
            double vpw = (double) values[i] / weights[i];
            items[i] = new Item(vpw, values[i], weights[i], i);
        }

        Arrays.sort(items, new Comparator<Item>() {
            @Override
            public int compare(Item a, Item b) {
                return Double.compare(b.valuePerWeight, a.valuePerWeight);
            }
        });

        int maxT = 0;
        for (int i = 0; i < n; i++) {
            if (weights[i] <= W && values[i] > maxT) {
                maxT = values[i];
            }
        }

        int totalWeight = 0;
        int greedyValue = 0;
        for (Item item : items) {
            if (totalWeight + item.weight <= W) {
                totalWeight += item.weight;
                greedyValue += item.value;
            } else {
                break;
            }
        }

        return Math.max(greedyValue, maxT);
    }

    public static void main(String[] args) {
        int[] values = { 60, 100, 120 };
        int[] weights = { 10, 20, 30 };
        int W = 50;
        int n = 3;

        int OPT = knapsack01(n, W, values, weights);
        System.out.println("Optimal value (OPT): " + OPT); // Outputs 220

        int G = greedySteal(n, W, values, weights);
        System.out.println("Greedy value (G): " + G); // Outputs 160

        double halfOPT = OPT / 2.0;
        System.out.println("1/2 OPT: " + halfOPT); // Outputs 110.0
        if (G >= halfOPT) {
            System.out.println("Bound holds: G >= (1/2) OPT");
        } else {
            System.out.println("Bound does not hold");
        }
    }
}