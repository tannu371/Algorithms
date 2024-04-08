/*
& Uses dynammic programming 
* Single source shortest path - finds shortest path from source node to all other node in the graph.
* Much more worst time complexity than dijkastra algorithm
! Time complexity of Bellman-ford : O(EV)
& In case of complete graph Time complexity : O(V³)
! Time complexity of Dijkastra : O((E+V)logV) when using a binary heap priority queue.
* Dijkastra fails when graph has negative edge weights.
* Bellman-ford detect negative cycles and determine where they occur.
& Application of Bellman-ford: In finanace, when performing an arbitrage between two or more markets.
^ Negative cycles: -ve self loops & cycle of loop whose net weight < 0.
^ All reachable by negative cycle have best cost of -ve infinity.
& Works with directed graph and with only those undirected graph which do not have negative weights. If undirected graph has a negative weight then it act as negative cycle (-ve self loop).
*/

#include<iostream>
#include<string>
#include<vector>

using namespace std;

struct Node {
    int id;
    string data;
    vector<Node*> children;
    Node(int id, string val) { this->id = id, this->data = val; }
};

class Edge {
public:
    Node* start;
    Node* end;
    float weight;
};

class Graph {
public:
    int E, V;
    vector<Node*> nodes;
    vector<Edge> edges;
    Graph();
    Node* find_node(string val);
};

bool compare(Node* n1, Node* n2) {
    return n1->data < n2->data;
}

Node* Graph::find_node(string val) {
    for (auto node : this->nodes) {
        if (node->data == val) return node;
    }
    return NULL;
}

Graph::Graph() {
    cout << "Enter number of vertices: ";
    cin >> this->V;
    cout << "Enter number of edges: ";
    cin >> this->E;

    string u, v;
    float w;
    cout << "Enter edges: " << endl;
    for (int i = 0; i < E; i++) {
        cin >> u >> v >> w;
        Node* start = find_node(u);
        Node* end = find_node(v);
        if (start == NULL) {
            start = new Node(this->nodes.size(), u);
            this->nodes.push_back(start);
        }
        if (end == NULL) {
            end = new Node(this->nodes.size(), v);
            this->nodes.push_back(end);
        }
        start->children.push_back(end);
        Edge e{ start, end, w };
        this->edges.push_back(e);
    }
    sort(this->nodes.begin(), this->nodes.end(), compare);
}

int* Bellman_ford(Graph G, Node* S) {
    int* D = new int[G.V];
    for (int i = 0; i < G.V; i++) {
        D[i] = INT_MAX;
    }
    D[S->id] = 0;

    for (int i = 0; i < G.V - 1; i++) {
        for (auto edge : G.edges) {
            // * Relax edges : update D with shorter path
            if (D[edge.start->id] == INT_MAX) continue;
            if (D[edge.start->id] + edge.weight < D[edge.end->id]) {
                D[edge.end->id] = D[edge.start->id] + edge.weight;
            }
        }
    }

    // * Repeat - to find nodes caught in a negative cycle
    for (int i = 0; i < G.V - 1; i++) {
        for (auto edge : G.edges) {
            if (D[edge.start->id] + edge.weight < D[edge.end->id]) {
                D[edge.end->id] = INT_MIN;
            }
        }
    }

    return D;
}



int main() {
    Graph g;

    string value;
    cout << "Enter start node value: ";
    cin >> value;
    Node* start_node = g.find_node(value);

    int* distance = Bellman_ford(g, start_node);

    cout << "Node\t" << "distance" << endl;
    for (auto node : g.nodes) {
        cout << node->data << '\t';
        if (distance[node->id] == INT_MIN) cout << "-INF" << endl;
        else if (distance[node->id] == INT_MAX) cout << "INF" << endl;
        else cout << distance[node->id] << endl;
    }
    cout << "Nodes with minimum distance equal to -INF are part of negative cycle.\n" << endl;
    cout << "Nodes with maximum distance equal to INF are disconnected from graph containing start vertex.\n" << endl;
}

/*
9
13
6 7 -50
7 8 -10
1 6 60
1 5 30
5 8 50
5 4 25
5 6 5
4 9 100
2 4 75
1 2 20
0 1 5
2 3 10
3 2 -15
*/

/*
^ initialize array pointer
^ always use print statement when you are lost
*/
