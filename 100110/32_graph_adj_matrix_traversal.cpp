#include <iostream>
#include <vector>
#include <queue>
#include <stack>

class Graph {
private:
    int numVertices;
    std::vector<std::vector<int>> adjMatrix;

    void dfsRecursive(int startVertex, std::vector<bool>& visited) {
        visited[startVertex] = true;
        std::cout << startVertex << " ";

        for (int i = 0; i < numVertices; ++i) {
            if (adjMatrix[startVertex][i] == 1 && !visited[i]) {
                dfsRecursive(i, visited);
            }
        }
    }

public:
    Graph(int V) {
        numVertices = V;
        adjMatrix.resize(V, std::vector<int>(V, 0));
    }

    void acceptGraph() {
        std::cout << "Enter " << numVertices << "x" << numVertices << " adjacency matrix (0 or 1):\n";
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                std::cin >> adjMatrix[i][j];
            }
        }
    }

    void displayAdjacencyMatrix() const {
        std::cout << "\nAdjacency Matrix:\n";
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                std::cout << adjMatrix[i][j] << " ";
            }
            std::cout << "\n";
        }
    }

    void bfsTraversal(int startVertex) {
        std::vector<bool> visited(numVertices, false);
        std::queue<int> q;

        visited[startVertex] = true;
        q.push(startVertex);

        std::cout << "BFS Traversal starting from vertex " << startVertex << ": ";
        while (!q.empty()) {
            int currentVertex = q.front();
            q.pop();
            std::cout << currentVertex << " ";

            for (int i = 0; i < numVertices; ++i) {
                if (adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
        std::cout << "\n"; 
    }

    void dfsTraversal(int startVertex) {
        std::vector<bool> visited(numVertices, false);
        std::cout << "DFS Traversal starting from vertex " << startVertex << ": ";
        dfsRecursive(startVertex, visited);
        std::cout << "\n"; 
    }
};

int main() {
    int V;
    std::cout << "Enter the number of vertices in the graph: ";
    std::cin >> V;

    Graph g(V);
    g.acceptGraph();

    g.displayAdjacencyMatrix();

    int start;
    std::cout << "Enter starting vertex for traversals (0 to " << V - 1 << "): ";
    std::cin >> start;

    if (start >= 0 && start < V) {
        g.bfsTraversal(start);
        g.dfsTraversal(start);
    } else {
        std::cout << "Invalid starting vertex." << std::endl;
    }

    return 0;
}