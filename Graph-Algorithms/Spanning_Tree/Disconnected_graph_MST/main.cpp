#include<iostream>
#include<set>

using namespace std;

class Edge {
public:
    int src;
    int dest;
    int weight;

    Edge(int u, int v, int w) {
        src = u;
        dest = v;
        weight = w;
    }

    bool operator< (const Edge & rhs) const {
        return this->weight < rhs.weight;
    } 
};

int findParent(int v, int* parent) {
    if(parent[v] == v) return v;
    return findParent(parent[v], parent);
}

void kruskal() {
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    set<Edge> edges;
    int m;
    cout << "Enter number of edges: ";
    cin >> m;

    int u, v, w;
    for(int i=0; i<m; i++) {
        cin >> u >> v >> w;
        edges.insert(Edge(u, v, w));
        edges.insert(Edge(v, u, w));
    }

    int* parent = new int[n];
    for(int i=0; i<n; i++) parent[i] = i;

    vector<Edge> MST;

    for(auto e : edges) {
        int srcParent = findParent(e.src, parent);
        int destParent = findParent(e.dest, parent);
        if(srcParent != destParent) {
            MST.push_back(e);
            parent[srcParent] = destParent;
        }
    }

    int x = n - MST.size();

    vector<Edge> MSTs[x];
    vector<Edge> temp;

    for (int i = 0; i < x; i++) {
        int p = findParent((*MST.begin()).src, parent);
        MSTs[i].push_back((*MST.begin()));
        MST.erase(MST.begin());
        for (auto e : MST) {
            if (p == findParent(e.src, parent)) MSTs[i].push_back(e);
            else temp.push_back(e);
        }
        MST.clear();
        MST = temp;
        temp.clear();
    }

    if(x > 1) {
        cout << "Graph is disconnected! " << endl;
        cout << "Possible Minimum spanning trees are :- " << endl;
    }

    for(int i=0; i<x; i++) {
        cout << "MST " << i+1 << endl;
        cout << "Edges\t" << "Weight" << endl;
        for(auto e: MSTs[i]) {
            if(e.src < e.dest) cout << e.src << ' ' << e.dest << '\t' << e.weight << endl;
            else  cout << e.dest << ' ' << e.src << '\t' << e.weight << endl;
        }
    }
    
}

int main() {
    kruskal();
}