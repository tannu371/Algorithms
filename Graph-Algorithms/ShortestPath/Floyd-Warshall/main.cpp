#include<iostream>

using namespace std;

#define INF 99999

// directed graph
int** create_cost_matrix(int n) {

    int m;
    cout << "Enter number of edges: ";
    cin >> m;

    int** cost_matrix;
    cost_matrix = new int*[n];
    for(int i=0; i<n; i++) cost_matrix[i] = new int[n];

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(i==j) cost_matrix[i][j] = 0;
            else cost_matrix[i][j] = INF;            
        }
    }
           
    int v1, v2; 
    // char v1, v2;
    int cost;
    cout << "Enter the pair of vertices representing the edges and weight: " << endl;

    for(int i=0; i<m; i++) {
        cin >> v1 >> v2 >> cost;
        cost_matrix[v1-1][v2-1] =  cost;
        // cost_matrix[v1-65][v2-65] = cost;
        // cost_matrix[v1-97][v2-97] = cost;          
    }
    
    return cost_matrix;
}

int min(int a, int b) {
    if(a<b) return a;
    else return b;
}

/*
! Robert Floyd and Stephen Warshall
& Solve all pair shortest path problem
! Time complexity: O(V³)
*/

int** Floyd_Warshall(int** cost_matrix, int n) {
    int** W;
    W = new int*[n];
    for(int i=0; i<n ; i++) {
        W[i] = new int[n];
        for(int j=0; j<n; j++) {
            W[i][j] = cost_matrix[i][j];
        }
    }

    for(int k=0; k<n; k++) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                W[i][j] = min(W[i][j], (W[i][k] + W[k][j]));
            }
        }
    }

    return W;
}

void print_matrix(int** matrix, int n) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << matrix[i][j] << '\t';
        }
        cout << endl;
    }
    cout << '\n' << endl;
}

int main() {
    int n;
    cout << "Enter number of vertix: ";
    cin >> n;

    int** cost_matrix;
    cost_matrix = create_cost_matrix(n);

    int** min_path;
    min_path = Floyd_Warshall(cost_matrix, n);

    print_matrix(min_path, n);
}

/* 
n=3 m=5
1 2 4
2 1 6
2 3 2
1 3 11
3 1 3
*/