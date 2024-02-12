// Shortest path problem
// A = 65, a = 97

#include<iostream>

using namespace std;

#define INF 999999

// Time Complexity O(n²)

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
           
    // int v1, v2; 
    char v1, v2;
    int cost;
    cout << "Enter the pair of vertices representing the edges and weight: " << endl;

    for(int i=0; i<m; i++) {
        cin >> v1 >> v2 >> cost;
        // cost_matrix[v1-1][v2-1] =  cost;
        // cost_matrix[v1-65][v2-65] = cost;
        cost_matrix[v1-97][v2-97] = cost;          
    }
    
    return cost_matrix;
}

int find_min(int array[], int v) {
    int minIndex = 0;
    for(int i=1; i<v; i++) {
        if(array[i] <= array[minIndex]) minIndex = i; 
    }
    return minIndex;
}

// visited[i] = 0 -> not visited
// visited[i] = 1 -> visited

// Edsger W. Dijkstra

void Dijkstra(int v0, int** cost, int n) {
    int visited[n];
    int distance[n];
    for(int i=0; i<n; i++) {
        visited[i]=0;
        // distance[i]=cost[v0-1][i];
        // distance[i]=cost[v0-65][i];
        distance[i]=cost[v0-97][i];
    } 

    // visited[v0-1] = 1;
    // visited[v0-65] = 1;
    visited[v0-97] = 1;
    // cout << v0 << " ";
    cout << char(v0) << " ";
    for (int k=2; k<n; k++) {
        int arr[n];
        for(int i=0; i<n; i++) {
            if (visited[i] == 0) arr[i] = distance[i];
            else arr[i] = INF;
        }
        int minIndex= find_min(arr, n);
        visited[minIndex] = 1;
        // cout << minIndex+1 << " ";
        // cout << char(minIndex+65) << " ";
        cout << char(minIndex+97) << " ";

        int chosen_v = minIndex;
        for(int i=0; i<n; i++) {
            if(visited[i]==0 && cost[chosen_v][i] != INF) {
                if(distance[i] > distance[chosen_v] + cost[chosen_v][i]) distance[i] = distance[chosen_v] + cost[chosen_v][i];
            }
        }
    }

    for(int i=0; i<n; i++) {
        if(!visited[i]) {
            // cout << i+1 << endl;
            // cout << char(i+65) << endl;
            cout << char(i+97) << endl;
        }  
    }
}



int main() {
    int n;
    cout << "Enter number of vertix: ";
    cin >> n;

    int** cost_matrix;
    cost_matrix = create_cost_matrix(n);
    Dijkstra('b', cost_matrix, n);
}

/* 
v = 8 e = 11
5 6 250
6 7 900
7 8 1000
6 8 1400
2 1 300
5 4 1500
4 3 1200
8 1 1700
3 1 1000
3 2 800
6 4 1000

v = 7 e = 12
bc 2
cd 10
de 6
ef 1
af 5
ab 4
bg 1
cg 3
gd 2
ge 4
gf 8 
ga 2
*/