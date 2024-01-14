// Optimal Merge Pattern
#include<iostream>

using namespace std;

// Two way merge tree
// Time complexity: O(n+m)

struct tree_node {
    tree_node* lchild = NULL;
    tree_node* rchild = NULL;
    int weight;
};

tree_node* Least(tree_node* node_list[], int &n) {
    tree_node* least = node_list[0];
    int index = 0;
    for(int i=1; i<n; i++) {
        if(node_list[i]->weight < least->weight) {
            least = node_list[i];
            index = i;
        } 
    }
    for(int i=index; i<n-1; i++) node_list[i] = node_list[i+1];
    n--;
    return least;
}

void Insert(tree_node* node_list[], tree_node* node, int &n) {
    node_list[n] = node;
    n++;
}

tree_node** create_node_list(int n) {
    tree_node** node_list;
    node_list = new tree_node*[n];
    cout << "Enter weights: ";
    for(int i=0; i<n; i++) {
        tree_node* newNode = new tree_node;
        cin >> newNode->weight;
        node_list[i] = newNode;
    } 
    return node_list;
}

// David Huffman

tree_node* Tree(int n) {
    tree_node** node_list = NULL; 
    node_list = create_node_list(n);
    int m =n;
    int Total_moves = 0;
    for(int i=0; i<n-1; i++) {
        tree_node* newNode = new tree_node;
        newNode->lchild = Least(node_list, m);
        newNode->rchild = Least(node_list, m);
        newNode->weight = newNode->lchild->weight + newNode->rchild->weight;
        Insert(node_list, newNode, m);
        Total_moves += newNode->weight;
    }

    cout << "Total moves: " << Total_moves << endl;
    
    return Least(node_list, m);
}

int main() {
    int n; 
    cout << "Enter number of files: ";
    cin >> n;
 
    Tree(n);
}

// n = 5
// 20 30 10 5 30

// n=10
// 2 13 15 22 25 30 35 55 84 97