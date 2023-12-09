import heapq

def prim(graph):
    n = len(graph)
    visited = [False] * n
    distance = [float('inf')] * n

    start_node = 0  
    distance[start_node] = 0
    priority_queue = [(0, start_node)]

    total_weight = 0

    while priority_queue:
        current_weight, current_node = heapq.heappop(priority_queue)

        if visited[current_node]:
            continue

        visited[current_node] = True
        total_weight += current_weight

        for neighbor, weight in graph[current_node]:
            if not visited[neighbor] and weight < distance[neighbor]:
                distance[neighbor] = weight
                heapq.heappush(priority_queue, (weight, neighbor))

    return total_weight

def main():
    t = int(input())  

    for _ in range(t):
        n = int(input())  
        graph = [[] for _ in range(n)]

        for i in range(n):
            node_info = list(map(int, input().split()))
            node = node_info[0] - 1  
            neighbors = node_info[2::2]
            weights = node_info[3::2]

            for neighbor, weight in zip(neighbors, weights):
                graph[node].append((neighbor - 1, weight))
                graph[neighbor - 1].append((node, weight))

        mst_weight = prim(graph)
        print(mst_weight)

if __name__ == "__main__":
    main()
