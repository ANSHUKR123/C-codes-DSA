#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <utility>

using namespace std;

const int MAXN = 100005;
vector<pair<int, int>> adj[MAXN];
int dist[MAXN], parent[MAXN];
bool visited[MAXN];

void prim(int start) {
    memset(visited, false, sizeof(visited));
    memset(parent, -1, sizeof(parent));
    memset(dist, 0x3f, sizeof(dist));  // Initialize dist to infinity
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    dist[start] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) {
            continue;
        }
        visited[u] = true;

        for (pair<int, int> edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;
            if (!visited[v] && weight < dist[v]) {
                parent[v] = u;
                dist[v] = weight;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    prim(1);  // Call Prim's algorithm starting from vertex 1

    // Print the MST edges and their weights
    for (int i = 1; i <= n; i++) {
        if (parent[i] != -1) {
            cout << parent[i] << " " << i << " " << dist[i] << endl;
        }
    }

    return 0;
}
