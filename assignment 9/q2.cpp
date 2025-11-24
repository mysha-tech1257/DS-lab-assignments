#include <iostream>
using namespace std;

int n, adj[20][20], visited[20] = {0};

void dfs(int u) {
    cout << u << " ";
    visited[u] = 1;

    for (int v = 0; v < n; v++) {
        if (adj[u][v] == 1 && visited[v] == 0)
            dfs(v);
    }
}

int main() {
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> adj[i][j];

    int start;
    cout << "Enter starting vertex (0 to " << n-1 << "): ";
    cin >> start;

    cout << "DFS Traversal: ";
    dfs(start);

    return 0;
}
