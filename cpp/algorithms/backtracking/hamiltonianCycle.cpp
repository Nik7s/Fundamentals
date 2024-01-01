#include <iostream>
#include <vector>

using namespace std;

class Graph {
public:
    Graph(int vertices);
    void addEdge(int v, int w);
    bool hasHamiltonianCycle();

private:
    int vertices;
    vector<vector<int>> adjacencyMatrix;
    bool isHamiltonianCycleUtil(vector<int>& path, int pos);
    bool isSafe(int v, vector<int>& path, int pos);
};

Graph::Graph(int vertices) {
    this->vertices = vertices;
    adjacencyMatrix.resize(vertices, vector<int>(vertices, 0));
}

void Graph::addEdge(int v, int w) {
    adjacencyMatrix[v][w] = 1;
    adjacencyMatrix[w][v] = 1;
}

bool Graph::hasHamiltonianCycle() {
    vector<int> path(vertices, -1);
    path[0] = 0; // Start from the first vertex

    if (!isHamiltonianCycleUtil(path, 1)) {
        cout << "Graph does not have a Hamiltonian cycle.\n";
        return false;
    }

    cout << "Hamiltonian cycle found:\n";
    for (int i = 0; i < vertices; ++i)
        cout << path[i] << " ";
    cout << path[0] << endl;

    return true;
}

bool Graph::isHamiltonianCycleUtil(vector<int>& path, int pos) {
    if (pos == vertices) {
        // Check if the last vertex is connected to the first vertex
        if (adjacencyMatrix[path[pos - 1]][path[0]] == 1)
            return true;
        else
            return false;
    }

    for (int v = 1; v < vertices; ++v) {
        if (isSafe(v, path, pos)) {
            path[pos] = v;

            if (isHamiltonianCycleUtil(path, pos + 1))
                return true;

            path[pos] = -1; // Backtrack
        }
    }

    return false;
}

bool Graph::isSafe(int v, vector<int>& path, int pos) {
    // Check if the vertex is adjacent to the last added vertex
    if (adjacencyMatrix[path[pos - 1]][v] == 0)
        return false;

    // Check if the vertex has not been visited before
    for (int i = 0; i < pos; ++i)
        if (path[i] == v)
            return false;

    return true;
}

int main() {
    Graph graph(5);

    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);
    graph.addEdge(4, 0);  

    if (!graph.hasHamiltonianCycle())
        cout << "No Hamiltonian cycle found.\n";

    return 0;
}
