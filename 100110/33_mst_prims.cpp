#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <utility>

class Graph {
private:
    int numVertices;
    std::vector<std::vector<int>> adjMatrix;

    void printMST(const std::vector<int>& parent, const std::vector<std::vector<int>>& graph) const {
        std::cout << "Edge \tWeight" << std::endl;
        int totalWeight = 0;
        for (int i = 1; i < numVertices; ++i) {
            std::cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << std::endl;
            totalWeight += graph[i][parent[i]];
        }
        std::cout << "Total MST Weight: " << totalWeight << std::endl;
    }

public:
    Graph(int V) {
        numVertices = V;
        adjMatrix.resize(V, std::vector<int>(V, 0));
    }

    void acceptGraph() {
        std::cout << "Enter the adjacency matrix of weights (Use 0 for no edge/self-loops, or a large number/INT_MAX for non-existent edge if using 0 for weight is possible):\n";
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                std::cin >> adjMatrix[i][j];
            }
        }
    }

    void primMST() {
        std::vector<int> parent(numVertices);
        std::vector<int> key(numVertices, INT_MAX);
        std::vector<bool> inMST(numVertices, false);

        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;

        key[0] = 0;
        parent[0] = -1;
        pq.push({0, 0});

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            if (inMST[u] == true) continue;

            inMST[u] = true;

            for (int v = 0; v < numVertices; ++v) {
                if (adjMatrix[u][v] != 0 && inMST[v] == false && adjMatrix[u][v] < key[v]) {
                    parent[v] = u;
                    key[v] = adjMatrix[u][v];
                    pq.push({key[v], v});
                }
            }
        }

        printMST(parent, adjMatrix); [Image of Prim's algorithm for minimum spanning tree]
    }
};

int main() {
    int V;
    std::cout << "Enter the number of vertices: ";
    std::cin >> V;

    Graph g(V);
    g.acceptGraph();

    std::cout << "\n--- Minimum Spanning Tree using Prim's Algorithm ---\n";
    g.primMST();

    return 0;
}