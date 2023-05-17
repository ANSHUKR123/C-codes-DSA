#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Utility function to perform DFS on a graph starting from a given vertex
void DFS(vector<vector<int>>& graph, int start, vector<bool>& visited) {
    // Create a stack for DFS
    stack<int> stk;

    // Push the starting vertex to the stack and mark it as visited
    stk.push(start);
    visited[start] = true;

    while (!stk.empty()) {
        // Pop a vertex from the stack and print it
        int currVertex = stk.top();
        stk.pop();
        cout << currVertex << " ";

        // Get all adjacent vertices of the popped vertex and process them
        for (int adjVertex : graph[currVertex]) {
            if (!visited[adjVertex]) {
                // If an adjacent vertex is not visited, mark it as visited and push it to the stack
                visited[adjVertex] = true;
                stk.push(adjVertex);
            }
        }
    }
}

// Function to add an edge to an undirected graph
void addEdge(vector<vector<int>>& graph, int u, int v) {
    graph[u].push_back(v);  // Add v to u's adjacency list
    graph[v].push_back(u);  // Add u to v's adjacency list
}

int main() {
    int numVertices = 6;
    vector<vector<int>> graph(numVertices);

    // Add edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);
    addEdge(graph, 3, 5);
    addEdge(graph, 4, 5);

    // Mark all vertices as not visited
    vector<bool> visited(numVertices, false);

    cout << "DFS Traversal starting from vertex 0: ";
    DFS(graph, 0, visited);

    return 0;
}
