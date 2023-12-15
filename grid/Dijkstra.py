def dijkstra(graph, start):
    n = len(graph)
    distance = [float('inf')] * n
    dist_ = [0] * n
    visited = [False] * n
    distance[start] = 0

    while not all(visited):
        min_distance = float('inf')
        current_node = -1

        for node in range(n):
            if not visited[node] and distance[node] < min_distance:
                min_distance = distance[node]
                current_node = node

        if current_node == -1:
            break

        visited[current_node] = True

        for neighbor, edge_weight in graph[current_node]:
            if not visited[neighbor] and distance[current_node] + edge_weight < distance[neighbor]:
                distance[neighbor] = distance[current_node] + edge_weight
                dist_[neighbor] = edge_weight

    return dist_

t = int(input())
for _ in range(t):
    graph = [[] for _ in range(1001)]
    n = int(input())
    for _ in range(n):
        node_info = list(map(int, input().split()))
        source_node = node_info[0]
        for k in range(node_info[1]):
            target_node, edge_weight = node_info[(k + 1) * 2], node_info[(k + 1) * 2 + 1]
            graph[source_node].append((target_node, edge_weight))

    dist_ = dijkstra(graph, 1)
    total_weight = sum(dist_[2:n + 1])
    print(total_weight)
