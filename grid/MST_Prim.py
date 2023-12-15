import heapq

def prim(graph, start):
    n = len(graph)
    visited = [False] * n
    distance = [float('inf')] * n
    distance[start] = 0
    priority_queue = [(0, start)]

    while priority_queue:
        current_distance, current_node = heapq.heappop(priority_queue)

        if visited[current_node]:
            continue

        visited[current_node] = True

        for neighbor, weight in graph[current_node]:
            if not visited[neighbor] and weight < distance[neighbor]:
                distance[neighbor] = weight
                heapq.heappush(priority_queue, (weight, neighbor))

    return distance

def main():
    t = int(input())
    for _ in range(t):
        n = int(input())
        graph = [[] for _ in range(1001)]

        for i in range(n):
            line = list(map(int, input().split()))
            u, m = line[0], line[1]

            for j in range(2, 2 * m + 2, 2):
                v, w_uv = line[j], line[j + 1]
                graph[u].append((v, w_uv))
                graph[v].append((u, w_uv))

        distances = prim(graph, 1)
        total_weight = sum(distances[2:n + 1])
        print(total_weight)

if __name__ == "__main__":
    main()
