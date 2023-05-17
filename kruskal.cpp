#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Define a structure to represent a graph edge
struct Edge {
    int src, dest, weight;
};

// Define a structure to represent a graph
struct Graph {
    int V, E;
    vector<Edge> edges;
};

// Define a structure to represent a subset for union-find
struct Subset {
    int parent;
    int rank;
};

// Find the parent of a subset using path compression
int find(Subset subsets[], int i) {
    if(subsets[i].parent != i) {
        subsets[i].parent = find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}

// Perform union of two subsets using rank
void Union(Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if(subsets[xroot].rank < subsets[yroot].rank) {
        subsets[xroot].parent = yroot;
    }
    else if(subsets[xroot].rank > subsets[yroot].rank) {
        subsets[yroot].parent = xroot;
    }
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Compare function used by sort() to sort edges by weight
bool Compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

// Run Kruskal's algorithm to find MST
void KruskalMST(Graph graph) {
    int V = graph.V;
    vector<Edge> result;

    // Sort edges by weight
    sort(graph.edges.begin(), graph.edges.end(), Compare);

    // Allocate memory for subsets
    Subset* subsets = new Subset[V];
    for(int v = 0; v < V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // Traverse sorted edges and add to MST if they don't form a cycle
    vector<Edge>::iterator it;
    for(it = graph.edges.begin(); it != graph.edges.end(); it++) {
        int x = find(subsets, it->src);
        int y = find(subsets, it->dest);

        if(x != y) {
            result.push_back(*it);
            Union(subsets, x, y);
        }
    }

    // Print the edges of the MST
    cout << "Edges of MST:" << endl;
    vector<Edge>::iterator i;
    for(i = result.begin(); i != result.end(); i++) {
        cout << i->src << " - " << i->dest << endl;
    }
}

// Driver function
int main() {
    // Create a graph
    Graph graph;
    graph.V = 4;
    graph.E = 5;
    graph.edges.push_back({0, 1, 10});
    graph.edges.push_back({0, 2, 6});
    graph.edges.push_back({0, 3, 5});
    graph.edges.push_back({1, 3, 15});
    graph.edges.push_back({2, 3, 4});

    // Find the MST using Kruskal's algorithm
    KruskalMST(graph);

    return 0;
}
