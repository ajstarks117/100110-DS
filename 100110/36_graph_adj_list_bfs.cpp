#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;

public:
    Graph(int v) {
        V = v;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void display() {
        for (int i = 0; i < V; i++) {
            cout << i << ": ";
            for (int x : adj[i]) cout << x << " ";
            cout << endl;
        }
    }

    void BFS(int start) {
        vector<bool> visited(V, false);
        queue<int> q;
        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << " ";

            for (int x : adj[node]) {
                if (!visited[x]) {
                    visited[x] = true;
                    q.push(x);
                }
            }
        }
    }
};

int main() {
    int V, E, u, v, start;
    cout << "Enter number of vertices: ";
    cin >> V;
    Graph g(V);

    cout << "Enter number of edges: ";
    cin >> E;

    for (int i = 0; i < E; i++) {
        cin >> u >> v;
        g.addEdge(u, v);
    }

    cout << "\nAdjacency List:\n";
    g.display();

    cout << "\nEnter starting vertex for BFS: ";
    cin >> start;

    cout << "BFS Traversal: ";
    g.BFS(start);
}
