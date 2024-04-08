#include<iostream>
#include<vector>
#include<utility>
#include<queue>

using namespace std;

/*
& Uses greedy approach
* shortest path from source node to all other nodes
& Doesnot work with negative weights
* Works with both directed and undirected graph.
& Time Complexity : 
! O(V²) with no use of priority queue
! O(E+Vlog₂V) with Fibonacci heap as priority queue
! O(Elog₂V) with binary heap as priority queue
*/

void dijkastra(vector<pair<int, int>>* adj, int n, int S) {
    int* d = new int[n];
    bool* visited = new bool[n];
    for (int v = 0; v < n; v++) {
        d[v] = INT_MAX;
        visited[v] = 0;
    }
    d[S] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0, S });

    cout << "Shortest Path: " << endl;
    cout << "Vertex\tDistance" << endl;
    while (!pq.empty()) {
        auto it = pq.top();
        pq.pop();
        int node = it.second;
        int dist = it.first;

        if (visited[node] == 0) {
            visited[node] = 1;
            cout << node << '\t' << dist << endl;
        }

        for (auto it : adj[node]) {
            int adjNode = it.second;
            int edgW = it.first;
            if (visited[adjNode] == 0 && dist + edgW < d[adjNode]) {
                d[adjNode] = dist + edgW;
                pq.push({ d[adjNode], adjNode });
            }
        }
    }

}

int main() {
    int n, m;
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> m;

    vector<pair<int, int>>* adj_list = new vector<pair<int, int>>;
    int u, v, w;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        adj_list[u].push_back({ w, v });
        adj_list[v].push_back({ w, u });
    }

    int source;
    cout << "Enter source vertex: ";
    cin >> source;
    dijkastra(adj_list, n, source);
}