#include <iostream>
using namespace std;

int main() {
    int n, adj[20][20], visited[20] = {0}, queue[20], front = 0, rear = -1, start;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> adj[i][j];

    cout << "Enter starting vertex (0 to " << n-1 << "): ";
    cin >> start;

    visited[start] = 1;
    queue[++rear] = start;

    cout << "BFS Traversal: ";

    while (front <= rear) {
        int u = queue[front++];
        cout << u << " ";

        for (int v = 0; v < n; v++) {
            if (adj[u][v] == 1 && visited[v] == 0) {
                visited[v] = 1;
                queue[++rear] = v;
            }
        }
    }
    return 0;
}
