// Minimum Spanning Tree

#include<iostream>

using namespace std;

// increasing order
template<typename T>
int partition(T c[], int low, int high) {
    int pIndex = low;
    int i=low, j=high;
    while(i<j) {
        while(c[i] <= c[pIndex] && i<high) i++;
        while(c[j] > c[pIndex]) j--;
        if(i<j) {
            T temp = c[i];
            c[i] = c[j];
            c[j] = temp;
            j--;
        }
    }
    T temp = c[pIndex];
    c[pIndex] = c[j];
    c[j] = temp;
    pIndex = j;
    return pIndex;
}

template<typename T>
void Quick_Sort(T c[], int low, int high) {
    if(low>=high) return;
    int pIndex = partition(c, low, high);
    Quick_Sort(c, low, pIndex-1);
    Quick_Sort(c, pIndex+1, high);
}

struct graph_edge{
    char u;
    char v;
    int weight;
    bool operator<= (const graph_edge &rhs) const {
        return this->weight <= rhs.weight;
    }

    bool operator> (const graph_edge &rhs) const {
        return this->weight > rhs.weight;
    }
};


class Graph {
    graph_edge** edges;
    
    Graph(int m) {

    }

    void addEdges() {

    }
};



// Joseph Kruskal 
// Sorting of weighted edges
// Time Complexity: O(Elog₂E)

graph_edge* Kruskal(graph_edge edges[],  int n, int m) {
    Quick_Sort(edges, 0, m);
    graph_edge* T;
    T = new graph_edge[n-1];

    int i=0;
    int j=0;
    while(i<n-1 && j<m) {
        graph_edge e = edges[j];
        bool flag1 = false;
        for(int j=0; j<i; j++) {
            if(T[j].u == e.u || T[j].v == e.u) flag1 = true;
        }
        bool flag2 = false;
        if(flag1) {
            for(int j=0; j<i; j++) {
                if(T[j].u == e.v || T[j].v == e.v) flag2 = true;
            }
        }
        if(!flag2) {
            T[i++] = e;
        }
        j++;
    }
    if(i<n-1) {
        cout << "No Spanning Tree exist." << endl;
    }
    return T;
}

int main() {
    int n, m;
    cout << "Enter number of vertex: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> m;

    Graph(m){this->m = m} {
        
    };
    
    graph_edge* edges;
    edges = new graph_edge[m];

    cout << "Enter the edges and weights: ";
    for(int i=0; i<m; i++) {
        cin >> edges[i].u >> edges[i].v;
        cin >> edges[i].weight;
    }

    graph_edge* T;
    T = Kruskal(edges, n, m);

    cout << "Edege\tWeight" << endl;
    for(int i=0; i<n-1; i++) {
        cout  << T[i].u << T[i].v << "\t" << T[i].weight << endl;
    }
}

/*
n=7 m=9
12 28
23 16
34 12
45 22
56 25
61 10
27 14
75 24
74 18
*/ 