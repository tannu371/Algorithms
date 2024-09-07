#include<iostream>
#include<vector>
using namespace std;

/*
* Hamiltonian path : path that visit each vertex exactly once.
* Hamiltonian cycle(circuit) : Hamiltonian path such that there is and edge from the last vertex to the first vertex.
* Hamiltonian graph: Any connected graph that contains a Hamiltonian cycle.
*/

bool HamiltonianCycle(vector<int>* graph, int V, int v, vector<int> path = {}, bool* visited = NULL) {
    if(visited == NULL) {
        if (V <= 0) return false;
        visited = new bool[V];
        for(int i=0; i<V; i++) visited[i] = false;
        visited[v] = true;
        path.push_back(v);
    }
    if(path.size() == V) {
        for(auto v: path) cout << v << " ";
        cout << endl;
        return true;
    }
    for(auto av: graph[v]) {
        if(visited[av] == false) {
            visited[av] = true;
            path.push_back(av);
            if (HamiltonianCycle(graph, V, av, path, visited)) return true;
            // ! Backtracking
            visited[av] = false;
            path.pop_back();
        }
    }
    return false;
}

int main() {
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    vector<int> graph[n];

    int e;
    cout << "Enter number of edges: ";
    cin >> e;

    cout << "Enter edges: ";
    int u, v;
    for(int i=0; i<e; i++) {
        cin >> u >> v;
        // ^ unweighted, undirected graph.
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    if(!HamiltonianCycle(graph, n, 0)) cout << "Hamiltonian cycle is not poassible for the given graph." << endl;

}

/*
n = 7 e = 12
0 1
0 3
0 4
0 5
1 2
1 4
1 5
2 3
2 4
2 6
3 4
3 6
*/