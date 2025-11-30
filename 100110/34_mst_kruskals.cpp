#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

struct Edge {
    int u, v, weight;
};

bool compareEdges(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

class DSU {
private:
    std::vector<int> parent;
public:
    DSU(int n) {
        parent.resize(n);
        std::iota(parent.begin(), parent.end(), 0);
    }
    
    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }

    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            parent[root_i] = root_j;
        }
    }
};

class Graph {
private:
    int numVertices;
    std::vector<Edge> edges;

public:
    Graph(int V) {
        numVertices = V;
    }

    void addEdge(int u, int v, int w) {
        edges.push_back({u, v, w});
    }

    void acceptGraph() {
        int E;
        std::cout << "Enter the number of edges: ";
        std::cin >> E;

        std::cout << "Enter the edges (start_vertex end_vertex weight):\n";
        for (int i = 0; i < E; ++i) {
            int u, v, w;
            std::cin >> u >> v >> w;
            addEdge(u, v, w);
        }
    }

    void kruskalMST() {
        std::sort(edges.begin(), edges.end(), compareEdges);

        DSU dsu(numVertices);
        std::vector<Edge> resultMST;
        int totalWeight = 0;

        for (const auto& edge : edges) {
            int root_u = dsu.find(edge.u);
            int root_v = dsu.find(edge.v);

            if (root_u != root_v) {
                resultMST.push_back(edge);
                dsu.unite(edge.u, edge.v);
                totalWeight += edge.weight;
            }
        }

        std::cout << "\nEdges in the Minimum Spanning Tree (Kruskal's):\n";
        std::cout << "Edge \tWeight" << std::endl;
        for (const auto& edge : resultMST) {
            std::cout << edge.u << " - " << edge.v << " \t" << edge.weight << std::endl;
        }
        std::cout << "Total MST Weight: " << totalWeight << std::endl; [Image of Kruskal's algorithm for minimum spanning tree]
    }
};

int main() {
    int V;
    std::cout << "Enter the number of vertices (0-indexed): ";
    std::cin >> V;

    Graph g(V);
    g.acceptGraph();

    g.kruskalMST();

    return 0;
}