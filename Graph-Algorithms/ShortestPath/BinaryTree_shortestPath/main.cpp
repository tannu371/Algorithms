#include<iostream>
using namespace std;

struct Node {
    int d;
    Node* left;
    Node* right;
};

void addNode(int k, Node* &root) {
    if (root == NULL) {
        Node* newNode = new Node;
        newNode->d = k;
        newNode->left = NULL;
        newNode->right = NULL;
        root = newNode;
        return;
    }
    if (k > root->d) addNode(k, root->right);
    else addNode(k, root->left);
}

Node* findLCA(Node* root, int p, int q) {
    if(root == NULL || root->d == p || root->d == q) {
        return root;
    }
    Node* left = findLCA(root->left, p, q);
    Node* right = findLCA(root->right, p, q);

    if(left == NULL) return right;
    else if(right == NULL) return left;
    else return root;
}

int findLevel(Node* root, int x, int level) {
    if(root == NULL) return -1;
    if(root->d == x) return level;
    int l = findLevel(root->left, x, level+1);
    return (l!= -1) ? l : findLevel(root->right, x, level+1);
}

int findShortestPath(Node* root, int p, int q) {
    Node* LCA = findLCA(root, p, q);
    int a = findLevel(LCA, p, 0);
    int b = findLevel(LCA, q, 0);
    return (a+b);
}

int main() {
    Node* root = NULL;
    int n;
    cout << "Enter number of node: ";
    cin >> n;
    cout << "Enter node values: ";
    int a;
    for(int i=0; i<n; i++) {
        cin >> a;
        addNode(a, root);
    }
    
    int x, y;
    cout << "Enter node values between which path is to be found: ";
    cin >> x >> y;

    int path = findShortestPath(root, x, y);
    cout << "Shortest path between " << x << " and " << y << " is: " << path << endl;
}