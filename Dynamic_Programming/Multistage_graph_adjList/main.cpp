#include <iostream>
#include<vector>
#include<queue>

using namespace std;

/*
* Minimum cost path from vertex s in V₁ to vertex t in V𝚔
& c[i, j] = cost of edge <i,j>
~ cost(i, j) = min cost from j in Vℹ to t
~ bcost(i, j) = min cost from s to j in Vℹ
& Forward Approach : cost(i, j) = min {c[j, l] + cost(i+1, l)}
& Backward Approach : bcost(i, j) = min {bcost(i-1, l) + c[l, j]}
! Time Complexity : ϴ(|V| + |E|)    (graph is represented as adjacency list)
*/

void BMultistageGraph(vector<pair<int, float>>* G, int k, int V, int* c, int i = 0, int* bcost = NULL) {
    if (bcost == NULL) {
        bcost = new int[V];
        for (int i = 0; i < V; i++) bcost[i] = INT_MAX;
        bcost[V-1] = 0.0;
    }
    if(bcost[i]!=INT_MAX) return;
    for (auto val : G[i]) {
        BMultistageGraph(G, k, V, c, val.first, bcost);
        if (bcost[i] > val.second + bcost[val.first]) {
            bcost[i] = val.second + bcost[val.first];
            c[i] = val.first;
        }
    }
}

int main() {
    int V;
    cout << "Enter number of vertices: ";
    cin >> V;
    vector<pair<int, float>> graph[V];
    int E;
    cout << "Enter number of edges: ";
    cin >> E;
    int k;
    cout << "Enter number of stages: ";
    cin >> k;
    int s;
    cout << "Enter source vertex: ";
    cin >> s;
    cout << "Enter edges: " << endl;
    int u, v;
    float w;
    for (int i = 0; i < E; i++) {
        cin >> u >> v >> w;
        u -= s, v -= s;
        graph[u].push_back({ v, w });
    }

    int* child = new int[V];
    for (int i = 0; i < V; i++) child[i] = i;
    BMultistageGraph(graph, k, V, child);
    
    cout << "Minimum cost path from source to sink: ";
    int i = 0;
    while (i != V - 1){
        if (s > 1) cout << char(i + s) << " ";
        else cout << i + s << " ";
        i = child[i];
    }
    if (s > 1) cout << char(i + s) << " ";
    else cout << i + s << " ";
    cout << endl;
}

/*
V = 12, E = 21, k = 5, S = 1
1 2 9
1 3 7
1 4 3
1 5 2
2 6 4
2 7 2
2 8 1
3 6 2
3 7 7
4 8 11
5 7 11
5 8 8
6 9 6
6 10 5
7 9 4
7 10 3
8 10 5
8 11 6
9 12 4
10 12 2
11 12 5
*/

/*
? Take care of base case, when you are returning
*/
