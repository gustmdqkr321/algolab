#include <iostream>

using namespace std;

const int MAX_N = 1001;

int adj_list[MAX_N][MAX_N];
bool visited[MAX_N];

void dfs_recursive(int start, int n, int component[], int& component_size) {
    if (component_size == 0) {
        visited[start] = true;
        component[component_size++] = start;
    }

    for (int neighbor = 1; neighbor <= n; ++neighbor) {
        if (adj_list[start][neighbor] && !visited[neighbor]) {
            visited[neighbor] = true;
            component[component_size++] = neighbor;
            dfs_recursive(neighbor, n, component, component_size);
        }
    }
}

void bubble_sort(int arr[], int n) {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n - i; ++j) {
            if (arr[j] < arr[j - 1]) {
                swap(arr[j], arr[j - 1]);
            }
        }
    }
}

int main() {
    int t;
    cin >> t;

    for (int test_case = 0; test_case < t; ++test_case) {
        int n;
        cin >> n;

        for (int i = 1; i <= n; ++i) {
            visited[i] = false;
            for (int j = 1; j <= n; ++j) {
                adj_list[i][j] = 0;
            }
        }

        for (int i = 1; i <= n; ++i) {
            int k, m;
            cin >> k >> m;

            for (int j = 0; j < m; ++j) {
                int v;
                cin >> v;
                adj_list[k][v] = 1;
                adj_list[v][k] = 1;
            }
        }

        int connected_component_sizes[MAX_N] = {0};
        int component_count = 0;

        for (int i = 1; i <= n; ++i) {
            if (!visited[i]) {
                int component[MAX_N] = {0};
                int component_size = 0;
                dfs_recursive(i, n, component, component_size);
                connected_component_sizes[component_count++] = component_size;
            }
        }

        // Bubble Sort
        bubble_sort(connected_component_sizes, component_count);

        // 출력
        cout << component_count << " ";
        for (int i = 0; i < component_count; ++i) {
            cout << connected_component_sizes[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
