#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

class Graph {
public:
    int V;
    vector<vector<pair<int, int>>> adj;

    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int findParent(int node, vector<int>& parent) {
        if (parent[node] == node) return node;
        return parent[node] = findParent(parent[node], parent);
    }

    void unionSet(int u, int v, vector<int>& parent, vector<int>& rank) {
        u = findParent(u, parent);
        v = findParent(v, parent);

        if (rank[u] < rank[v]) parent[u] = v;
        else if (rank[v] < rank[u]) parent[v] = u;
        else {
            parent[v] = u;
            rank[u]++;
        }
    }

    void KruskalMST() {
        vector<pair<int, pair<int, int>>> edges;

        for (int u = 0; u < V; u++) {
            for (auto p : adj[u]) {
                int v = p.first;
                int w = p.second;
                if (u < v)
                    edges.push_back({w, {u, v}});
            }
        }

        sort(edges.begin(), edges.end());

        vector<int> parent(V), rank(V, 0);
        for (int i = 0; i < V; i++) parent[i] = i;

        int cost = 0;
        cout << "\nKruskal's MST Edges:\n";

        for (auto e : edges) {
            int w = e.first;
            int u = e.second.first;
            int v = e.second.second;

            if (findParent(u, parent) != findParent(v, parent)) {
                cost += w;
                cout << u << " -- " << v << "  weight = " << w << endl;
                unionSet(u, v, parent, rank);
            }
        }

        cout << "Total Minimum Cost = " << cost << endl;
    }

    void PrimMST() {
        vector<int> key(V, INT_MAX);
        vector<int> parent(V, -1);
        vector<bool> mst(V, false);

        key[0] = 0;

        for (int i = 0; i < V - 1; i++) {
            int u = -1;
            for (int v = 0; v < V; v++) {
                if (!mst[v] && (u == -1 || key[v] < key[u]))
                    u = v;
            }

            mst[u] = true;

            for (auto p : adj[u]) {
                int v = p.first;
                int w = p.second;

                if (!mst[v] && w < key[v]) {
                    key[v] = w;
                    parent[v] = u;
                }
            }
        }

        int cost = 0;
        cout << "\nPrim's MST Edges:\n";
        for (int i = 1; i < V; i++) {
            cout << parent[i] << " -- " << i << "  weight = " << key[i] << endl;
            cost += key[i];
        }
        cout << "Total Minimum Cost = " << cost << endl;
    }

    void Dijkstra(int src) {
        vector<int> dist(V, INT_MAX);
        vector<bool> visited(V, false);

        dist[src] = 0;

        for (int i = 0; i < V - 1; i++) {
            int u = -1;
            for (int v = 0; v < V; v++) {
                if (!visited[v] && (u == -1 || dist[v] < dist[u]))
                    u = v;
            }

            visited[u] = true;

            for (auto p : adj[u]) {
                int v = p.first;
                int w = p.second;

                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                }
            }
        }

        cout << "\nDijkstra Shortest Distances from node " << src << ":\n";
        for (int i = 0; i < V; i++) {
            cout << "Node " << i << " : " << dist[i] << endl;
        }
    }
};

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;

    Graph g(V);

    cout << "Enter number of edges: ";
    cin >> E;

    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }

    int choice;
    while (true) {
        cout << "\n===== GRAPH ALGORITHMS MENU =====\n";
        cout << "1. Kruskal's MST\n";
        cout << "2. Prim's MST\n";
        cout << "3. Dijkstra's Algorithm\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 0) break;

        switch (choice) {
            case 1: g.KruskalMST(); break;
            case 2: g.PrimMST(); break;
            case 3: {
                int src;
                cout << "Enter source vertex: ";
                cin >> src;
                g.Dijkstra(src);
                break;
            }
            default: cout << "Invalid Input!\n"; 
        }
    }

    return 0;
}
