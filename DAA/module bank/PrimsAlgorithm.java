import java.util.*;

public class PrimsAlgorithm {
    static int primsAlgorithm(List<List<int[]>> graph, int n) {
        int mstCost = 0;
        boolean[] visited = new boolean[n];
        int[] edgeWeights = new int[n];
        Arrays.fill(edgeWeights, Integer.MAX_VALUE);
        edgeWeights[0] = 0;

        for (int i = 0; i < n; i++) {
            int minWeight = Integer.MAX_VALUE, currentNode = -1;
            for (int j = 0; j < n; j++) {
                if (!visited[j] && edgeWeights[j] < minWeight) {
                    minWeight = edgeWeights[j];
                    currentNode = j;
                }
            }
            mstCost += minWeight;
            visited[currentNode] = true;

            for (int[] neighbor : graph.get(currentNode)) {
                int node = neighbor[0], weight = neighbor[1];
                if (!visited[node] && weight < edgeWeights[node]) {
                    edgeWeights[node] = weight;
                }
            }
        }
        return mstCost;
    }

    static int newMSTCost(int originalCost, int numEdges) {
        return originalCost + numEdges;
    }

    public static void main(String[] args) {
        List<List<int[]>> graph = new ArrayList<>();
        int n = 4;
        for (int i = 0; i < n; i++) graph.add(new ArrayList<>());
        
        graph.get(0).add(new int[]{1, 2});
        graph.get(0).add(new int[]{3, 6});
        graph.get(1).add(new int[]{0, 2});
        graph.get(1).add(new int[]{2, 3});
        graph.get(1).add(new int[]{3, 8});
        graph.get(2).add(new int[]{1, 3});
        graph.get(2).add(new int[]{3, 7});
        graph.get(3).add(new int[]{0, 6});
        graph.get(3).add(new int[]{1, 8});
        graph.get(3).add(new int[]{2, 7});

        int originalCost = primsAlgorithm(graph, n);
        int updatedCost = newMSTCost(originalCost, n - 1);
        
        System.out.println("Original MST Cost: " + originalCost);
        System.out.println("Updated MST Cost: " + updatedCost);
    }
}