#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Node {
public:
    string value;
    int weight;
    vector<Node*> children;

    Node(string v, int w);
};

Node::Node(string v, int w) {this->value = v, this->weight = w;}

// * dfs
void add_node(string u, string v, int w, Node* &root) {
    if(root == NULL) {
        Node* newNode = new Node(u, 0);
        root = newNode;
    }
    if(root->value == u) {
        Node* newNode = new Node(v, w);
        root->children.push_back(newNode);
        return;
    }
    if (root->children.size() == 0) return;
    for(auto child: root->children) 
        add_node(u, v, w, child);
}

// * dfs
void tree_splitting(vector<Node*> &result, Node* root, int tolerance, int total_cost = 0) {
    if(root->children.size() == 0)  {
        return;
    }
    for(auto child : root->children) {
        int cost = total_cost + child->weight;
        if(cost > tolerance) {
            cost = 0;
            result.push_back(child);
        } 
        tree_splitting(result, child, tolerance, cost);
    }
}

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;
    Node* root = NULL;
    cout << "Enter edges (start vertex, end vertex and weight): " << endl;
    string u, v;
    int w;

    for(int i=1; i<n; i++) {
        cin >> u >> v >> w;
        add_node(u, v, w, root);
    }
    
    int tol;
    cout << "Enter tolerance limit: ";
    cin >> tol;

    vector<Node*> vertices;
    tree_splitting(vertices, root, tol);

    int m = vertices.size();
    cout << "Total number of splits required: " << m << endl;
    cout << "Split at vertices: ";
    for(int i=0; i<m; i++) {
        cout << vertices[i]->value << " ";
    }
    cout << '\n' << endl;
}

/*
1 2 4
1 3 2
2 4 2
3 5 1
3 6 3
4 7 1
4 8 4
5 9 2
6 10 3

a b 4
a c 2
b d 2
c e 1
c f 3
d g 1
d h 4
e i 2
f j 3

A B 4
A C 2
B D 2
C E 1
C F 3
D G 1
D H 4
E I 2
F J 3

*/

/*
^ modifing variable must be passed by reference in function.
^ use auto val in for loop when required.
^ index out of bound is most common error.
*/