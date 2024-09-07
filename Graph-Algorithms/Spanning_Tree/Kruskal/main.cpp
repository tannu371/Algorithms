// Minimum Spanning Tree
#include<iostream>

using namespace std;

/* 
    * Joseph Kruskal 
    & Sorting of weighted edges.
    & Make sure added wedge in MST do not for cycle.
    ! Time Complexity : O(E+VlogV) = O(ElogV)
*/

struct edge {
    int u;
    int v;
    int weight;
};

bool compare(edge e1, edge e2) {
    return e1.weight < e2.weight;
}

// Find Parent Function
int findParent(int v, int* parent) {
    if (parent[v] == v) return v;
    return findParent(parent[v], parent);
}

void Kruskal(edge* edges, int n, int m) {
    sort(edges, edges + m, compare);
    edge* MST = new edge[n - 1];

    int* parent = new int[n];
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    int i = 0;
    int j = 0;
    int cost = 0;
    while (i < n - 1 && j < m) {
        edge current_edge = edges[j];

        // Find parent
        // & Check if we can add the current edge in MST or not.
        int sourceParent = findParent(current_edge.u, parent);
        int destParent = findParent(current_edge.v, parent);

        // Union set (u, v)
        if (sourceParent != destParent) {
            MST[i] = current_edge;
            i++;
            parent[sourceParent] = destParent;
            cost += current_edge.weight;
        }

        j++;
    }

    cout << "Edge\tWeight" << endl;
    for (int i = 0; i < n - 1; i++) {
        if (MST[i].u < MST[i].v) {
            cout << i + 1 << ") " << MST[i].u << " " << MST[i].v << "\t" << MST[i].weight << endl;
        }
        else {
            cout << i + 1 << ") " << MST[i].v << " " << MST[i].u << "\t" << MST[i].weight << endl;
        }
    }

    cout << "Total cost of MST: " << cost << endl;
}

int main() {
    int n, m;
    cout << "Enter number of vertex: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> m;



    edge* edges;
    edges = new edge[m];

    int s, d, w;
    cout << "Enter the edges and weights: " << endl;
    for (int i = 0; i < m; i++) {
        cin >> s >> d >> w;
        edges[i].u = s;
        edges[i].v = d;
        edges[i].weight = w;
    }

    Kruskal(edges, n, m);
}

/*
n=7 m=9
0 1 28
1 2 16
2 3 12
3 4 22
4 5 25
5 0 10
1 6 14
6 4 24
6 3 18
*/