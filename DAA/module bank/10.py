def prims_algorithm(graph, n):
    mst_cost = 0
    visited = [False] * n
    edge_weights = [float('inf')] * n
    edge_weights[0] = 0  # Start from node 0

    for _ in range(n):
        # Find the unvisited node with the smallest edge weight
        min_weight = float('inf')
        current_node = -1
        for i in range(n):
            if not visited[i] and edge_weights[i] < min_weight:
                min_weight = edge_weights[i]
                current_node = i

        # Add the smallest edge weight to the MST
        mst_cost += min_weight
        visited[current_node] = True

        # Update the edge weights of the neighbors of the current node
        for neighbor, weight in graph[current_node]:
            if not visited[neighbor] and weight < edge_weights[neighbor]:
                edge_weights[neighbor] = weight

    return mst_cost

def new_mst_cost(original_cost, num_edges):
    return original_cost + num_edges

# Example graph as adjacency list
# Graph represented as a list of adjacency lists: graph[node] = [(neighbor, weight), ...]
graph = {
    0: [(1, 2), (3, 6)],
    1: [(0, 2), (2, 3), (3, 8)],
    2: [(1, 3), (3, 7)],
    3: [(0, 6), (1, 8), (2, 7)]
}

n = len(graph)  # Number of nodes in the graph
num_edges = n - 1  # Number of edges in the MST

# Calculate the original MST cost using Prim's algorithm
original_cost = prims_algorithm(graph, n)

# Calculate the new MST cost after increasing all edge weights by 1
updated_cost = new_mst_cost(original_cost, num_edges)

# Output results
print("Original MST Cost:", original_cost)
print("Updated MST Cost:", updated_cost)
