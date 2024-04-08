
#include<iostream>

using namespace std;

int find_min(int *array, int size, int *visited) {
    int min = INT_MAX;
    int minIndex;
    for(int i=0; i<size; i++) {
        if(visited[i] == 0 && array[i] < min) {
            minIndex = i;
            min = array[i];
        } 
    }
    return minIndex;
}

// visited[i] = 0 -> not visited
// visited[i] = 1 -> visited

// & Edsger W. Dijkstra

void Dijkstra(int v0, int** cost, int n) {
    int visited[n];
    int distance[n];
    for(int i=0; i<n; i++) {
        visited[i]=0;
        distance[i] = INT_MAX;
    } 
    distance[v0] = 0;

    cout <<"Vertex\tDistance" << endl;
    for (int k=0; k<n; k++) {
        int minIndex= find_min(distance, n, visited);
        visited[minIndex] = 1;

        cout << minIndex << '\t' << distance[minIndex] << endl;

        int chosen_v = minIndex;
        for(int i=0; i<n; i++) {
            if(cost[chosen_v][i] != INT_MAX) {
                if (visited[i] == 0 && distance[i] > distance[chosen_v] + cost[chosen_v][i]) {
                    distance[i] = distance[chosen_v] + cost[chosen_v][i];
                }
            }
        }
    }
}



int main() {
    int n;
    cout << "Enter number of vertix: ";
    cin >> n;

    int m;
    cout << "Enter number of edges: ";
    cin >> m;

    int** cost_matrix = new int* [n];

    int v1, v2, cost;
    cout << "Enter the pair of vertices representing the edges and weight: " << endl;
    for (int i = 0; i < n; i++) {
        cost_matrix[i] = new int[n];
        for (int j = 0; j < n; j++) {
            if (i == j) cost_matrix[i][j] = 0;
            else cost_matrix[i][j] = INT_MAX;
        }
    }


    for (int i = 0; i < m; i++) {
        cin >> v1 >> v2 >> cost;
        cost_matrix[v1][v2] = cost;
        cost_matrix[v2][v1] = cost;
    }

    int s;
    cout << "Enter source vertex: ";
    cin >> s;

    Dijkstra(s, cost_matrix, n);
}

/* 
v = 8 e = 11
4 5 250
5 6 900
6 7 1000
5 7 1400
1 0 300
4 3 1500
3 2 1200
7 0 1700
2 0 1000
2 1 800
5 3 1000

*/