#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// function to perform BFS on the graph
void bfs(vector<vector<int>>& graph, int start) {
    int num_vertices = graph.size(); // get the number of vertices in the graph

    // create a boolean array to keep track of visited vertices
    vector<bool> visited(num_vertices, false);

    // create a queue to store the vertices to visit
    queue<int> vertex_queue;

    // mark the starting vertex as visited and add it to the queue
    visited[start] = true;
    vertex_queue.push(start);

    // loop until the queue is empty
    while (!vertex_queue.empty()) {
        // dequeue a vertex from the queue
        int current_vertex = vertex_queue.front();
        vertex_queue.pop();

        // output the current vertex
        cout << current_vertex << " ";

        // loop through the adjacent vertices of the current vertex
        for (int i = 0; i < graph[current_vertex].size(); i++) {
            int adjacent_vertex = graph[current_vertex][i];

            // if the adjacent vertex hasn't been visited, mark it as visited and add it to the queue
            if (!visited[adjacent_vertex]) {
                visited[adjacent_vertex] = true;
                vertex_queue.push(adjacent_vertex);
            }
        }
    }
}

int main() {
    // create a graph represented as an adjacency list
    vector<vector<int>> graph = {
        {1, 2},     // vertex 0 is adjacent to vertices 1 and 2
        {0, 2, 3},  // vertex 1 is adjacent to vertices 0, 2, and 3
        {0, 1, 3},  // vertex 2 is adjacent to vertices 0, 1, and 3
        {1, 2}      // vertex 3 is adjacent to vertices 1 and 2
    };

    // perform BFS starting from vertex 0
    cout << "BFS traversal starting from vertex 0:" << endl;
    bfs(graph, 0);

    return 0;
}
