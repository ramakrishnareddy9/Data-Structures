import java.util.*;

class Node implements Comparable<Node> {
    int[][] reducedMatrix;
    List<Integer> path;
    int cost;
    int level;
    int vertex;

    Node(int[][] matrix, List<Integer> path, int level, int vertex, int cost) {
        this.reducedMatrix = matrix;
        this.path = path;
        this.level = level;
        this.vertex = vertex;
        this.cost = cost;
    }

    public int compareTo(Node other) {
        return this.cost - other.cost;
    }
}

public class TSP_LCBB {
    static final int INF = Integer.MAX_VALUE;

    static int reduceMatrix(int[][] matrix) {
        int cost = 0;

        for (int i = 0; i < matrix.length; i++) {
            int rowMin = INF;
            for (int j = 0; j < matrix.length; j++)
                rowMin = Math.min(rowMin, matrix[i][j]);
            if (rowMin != INF && rowMin != 0) {
                cost += rowMin;
                for (int j = 0; j < matrix.length; j++)
                    if (matrix[i][j] != INF)
                        matrix[i][j] -= rowMin;
            }
        }

        for (int j = 0; j < matrix.length; j++) {
            int colMin = INF;
            for (int i = 0; i < matrix.length; i++)
                colMin = Math.min(colMin, matrix[i][j]);
            if (colMin != INF && colMin != 0) {
                cost += colMin;
                for (int i = 0; i < matrix.length; i++)
                    if (matrix[i][j] != INF)
                        matrix[i][j] -= colMin;
            }
        }

        return cost;
    }

    static Node createNode(Node parent, int i, int j, int[][] graph) {
        int n = graph.length;
        int[][] matrix = new int[n][n];

        for (int x = 0; x < n; x++)
            matrix[x] = parent.reducedMatrix[x].clone();

        for (int k = 0; k < n; k++) {
            matrix[i][k] = INF;
            matrix[k][j] = INF;
        }
        matrix[j][0] = INF;

        List<Integer> newPath = new ArrayList<>(parent.path);
        newPath.add(j);

        int addedCost = parent.reducedMatrix[i][j];
        int childCost = parent.cost + addedCost + reduceMatrix(matrix);

        return new Node(matrix, newPath, parent.level + 1, j, childCost);
    }

    static int solve(int[][] graph) {
        int n = graph.length;

        int[][] matrix = new int[n][n];
        for (int i = 0; i < n; i++)
            matrix[i] = graph[i].clone();

        int baseCost = reduceMatrix(matrix);

        PriorityQueue<Node> pq = new PriorityQueue<>();
        List<Integer> path = new ArrayList<>();
        path.add(0);

        pq.add(new Node(matrix, path, 1, 0, baseCost));

        int minCost = INF;

        while (!pq.isEmpty()) {
            Node minNode = pq.poll();

            if (minNode.cost >= minCost)
                continue;

            if (minNode.level == n) {
                int last = minNode.vertex;
                if (graph[last][0] != INF) {
                    int finalCost = minNode.cost + graph[last][0];
                    if (finalCost < minCost) {
                        minCost = finalCost;
                    }
                }
                continue;
            }

            for (int j = 0; j < n; j++) {
                if (minNode.reducedMatrix[minNode.vertex][j] != INF) {
                    Node child = createNode(minNode, minNode.vertex, j, graph);
                    if (child.cost < minCost) {
                        pq.add(child);
                    }
                }
            }
        }

        return minCost;
    }

    public static void main(String[] args) {
        int[][] graph = {
                { INF, 10, 15, 20 },
                { 10, INF, 35, 25 },
                { 15, 35, INF, 30 },
                { 20, 25, 30, INF }
        };

        int minCost = solve(graph);
        System.out.println("Minimum cost: " + minCost);
    }
}