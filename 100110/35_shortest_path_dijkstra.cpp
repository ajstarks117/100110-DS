#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
    int V;
    vector<vector<pair<int,int>>> adj;

public:
    Graph(int v) {
        V = v;
        adj.resize(V);
    }

    void addEdge(int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    void dijkstra(int src, int dest) {
        vector<int> dist(V, 1e9);
        vector<bool> visited(V, false);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            int node = pq.top().second;
            pq.pop();

            if (visited[node]) continue;
            visited[node] = true;

            for (auto x : adj[node]) {
                int next = x.first;
                int weight = x.second;

                if (dist[node] + weight < dist[next]) {
                    dist[next] = dist[node] + weight;
                    pq.push({dist[next], next});
                }
            }
        }

        if (dist[dest] == 1e9)
            cout << "No path exists";
        else
            cout << "Shortest Distance: " << dist[dest];
    }
};

int main() {
    int V, E, u, v, w, src, dest;

    cout << "Enter number of vertices: ";
    cin >> V;
    Graph g(V);

    cout << "Enter number of edges: ";
    cin >> E;

    for (int i = 0; i < E; i++) {
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }

    cout << "Enter source: ";
    cin >> src;
    cout << "Enter destination: ";
    cin >> dest;

    g.dijkstra(src, dest);
}
