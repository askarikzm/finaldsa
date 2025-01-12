#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAX_VERTICES = 5;
void BFS(int graph[][MAX_VERTICES], int start, int numVertices) {
    vector<bool> visited(numVertices, false); // Array to track visited nodes
    queue<int> q;                        // Queue to process vertices in BFS order

    // Start BFS from the given node
    visited[start] = true;
    q.push(start);

    cout << "BFS Traversal: ";
    while (!q.empty()) {
        int current = q.front(); // Get the front of the queue
        q.pop();
        cout << current << " ";  // Process the current node

        // Visit all neighbors of the current node
        for (int i = 0; i < numVertices; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
    cout << endl;
}

int main() {
    // Adjacency matrix representation of the graph
    int graph[5][5] = {
        {0, 1, 1, 0, 0},  // Connections for vertex 0
        {1, 0, 0, 1, 1},  // Connections for vertex 1
        {1, 0, 0, 0, 1},  // Connections for vertex 2
        {0, 1, 0, 0, 0},  // Connections for vertex 3
        {0, 1, 1, 0, 0}   // Connections for vertex 4
    };

    int startVertex = 0; // Starting vertex
    BFS(graph, startVertex, 5);

    return 0;
}