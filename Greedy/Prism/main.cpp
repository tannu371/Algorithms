// Minimum Spanning Tree

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

//& developed by Vojtěch Jarník in 1930
//& republished by Robert C. Prim in 1957

void Prims(vector<pair<int, int>> *adj_list, int n, int source) {
    bool *visited = new bool[n];
    for(int i=0; i<n; i++) {
        visited[i] = 0;
    }
    int cost = 0;
    priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});
    int prev = source;
    while(!pq.empty()) {
        auto it = pq.top();
        pq.pop();
        int v = it.second;
        int w = it.first;
        
        if(visited[v] == 1) continue;

        visited[v] = 1;
        if(prev != v) {
            cout << prev << " " << v << "\t" << w << endl;
        }
        prev = v;
        cost += w;

        for(auto it : adj_list[v]) {
            if(!visited[it.second]) pq.push(it);
        }
    }

    cout << "Total cost of MST: " << cost << endl;
}

int main() {
    int n, m;
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> m;

    vector<pair<int, int>> adj[n];
    int u, v , w;
    for(int i=0; i<m; i++) {
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }

    int source;
    cout << "Enter source vertex: ";
    cin >> source;

    Prims(adj, n, source);
    
}