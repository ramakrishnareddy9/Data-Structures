import java.util.*;

class Item {
    int weight, profit;
    double ratio;

    Item(int w, int p) {
        weight = w;
        profit = p;
        ratio = (double) p / w;
    }
}

class Node {
    int level, profit, weight;
    double bound;

    Node(int level, int profit, int weight, double bound) {
        this.level = level;
        this.profit = profit;
        this.weight = weight;
        this.bound = bound;
    }
}

public class KnapsackLCBB {
    static int n = 4;
    static int W = 15;
    static Item[] items = {
            new Item(2, 40),
            new Item(5, 30),
            new Item(10, 50),
            new Item(5, 10) };

    static double bound(Node u) {
        if (u.weight >= W)
            return 0;

        double profitBound = u.profit;
        int j = u.level;
        int totalWeight = u.weight;

        while (j < n && totalWeight + items[j].weight <= W) {
            totalWeight += items[j].weight;
            profitBound += items[j].profit;
            j++;
        }

        if (j < n)
            profitBound += (W - totalWeight) * items[j].ratio;

        return profitBound;
    }

    public static int knapsack() {
        Arrays.sort(items, (a, b) -> Double.compare(b.ratio, a.ratio));

        Queue<Node> q = new PriorityQueue<>((a, b) -> Double.compare(b.bound, a.bound));
        Node u, v;
        u = new Node(0, 0, 0, 0);
        u.bound = bound(u);
        q.add(u);

        int maxProfit = 0;

        while (!q.isEmpty()) {
            u = q.poll();

            if (u.bound <= maxProfit)
                continue;

            if (u.level < n) {
                // Include current item
                v = new Node(u.level + 1, u.profit + items[u.level].profit, u.weight + items[u.level].weight, 0);
                if (v.weight <= W) {
                    if (v.profit > maxProfit)
                        maxProfit = v.profit;
                    v.bound = bound(v);
                    if (v.bound > maxProfit)
                        q.add(new Node(v.level, v.profit, v.weight, v.bound));
                }

                // Exclude current item
                v = new Node(u.level + 1, u.profit, u.weight, 0);
                v.bound = bound(v);
                if (v.bound > maxProfit)
                    q.add(v);
            }
        }
        return maxProfit;
    }

    public static void main(String[] args) {
        int max = knapsack();
        System.out.println("Maximum profit: " + max);
    }
}