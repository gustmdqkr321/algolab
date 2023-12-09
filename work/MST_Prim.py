from collections import deque

def find(x, parent):
    if parent[x] != x:
        parent[x] = find(parent[x], parent)
    return parent[x]

def union(a, b, parent):
    ar = find(a, parent)
    br = find(b, parent)
    if ar < br:
        parent[br] = ar
    elif ar > br:
        parent[ar] = br

def process_input():
    num_cases = int(input())
    
    for _ in range(num_cases):
        num_nodes = int(input())
        parent = [i for i in range(num_nodes + 1)]
        edges = []
        total_weight = 0

        for _ in range(num_nodes):
            k, m, *tmp = map(int, input().split())

            for i in range(m):
                node, weight = tmp[2*i], tmp[2*i+1]
                edges.append((k, node, weight))

        edges.sort(key=lambda x: x[2])
        edges = deque(edges)

        while edges:
            a, b, w = edges.popleft()
            if find(a, parent) != find(b, parent):
                union(a, b, parent)
                total_weight += w

        print(total_weight)

if __name__ == "__main__":
    process_input()
