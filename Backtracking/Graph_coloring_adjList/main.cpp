#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

/*
* n-node graph and m-color
* height of state space = n+1
! Time Complexity : O(nmⁿ)
^ unweighted, undirected graph
*/

int solutions = 0;

bool isValid(vector<int>* graph, int* color, int c, int u) {
    for(auto v : graph[u]) {
        if(color[v] == c) return false;
    }
    return true;
}

void graphColoring(vector<int>* graph, int n, int m, int v = 0, int* color=NULL) {
    if(color == NULL) {
        color = new int[n];
    }
    if(v == n) {
        if(n<=0) return;
        ++solutions;
        cout << "Option " << solutions << " : " << endl;
        for(int i=0; i<n; i++) {
            cout << i << " : " << color[i] << "\t" << endl;
        }
        cout << endl;
        return;
    }
    for(int c=1; c<=m; c++) {
        if(isValid(graph, color, c, v)) {
            color[v] = c;
            graphColoring(graph,n, m, v+1, color);
            // ! Backtracking
            color[v] = 0;
        }
    }
}


// ! THis code is Dirty
int smallestColor(vector<int>* graph, int*color, int u) {
    for(auto v : graph[u]) {
        if(color[v] != 0) vec.push_back(color[v]);
    }
    sort(vec.begin(), vec.end());
    for(int i=1; i<=vec.size(); i++) {
        if(vec[i-1] != i) return i;
    } 
    return vec.size()+1;
}

int chromaticN(vector<int>* graph, int n, int m, int* color=NULL) {
    if(color == NULL) {
        color = new int[n];
        for(int i=0; i<n; i++) color[i] = 0;
    }
    int max = 0;
    for(int v=0; v<n; v++) {
        color[v] = smallestColor(graph, color, v);
        if(color[v] > max) max = color[v];
    }
    return max;
}

// ! Upto this

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;
    
    int e;
    cout << "Enter number of edges: ";
    cin >> e;

    vector<int> graph[n];
    cout << "Enter edges: " << endl;
    int u, v;
    for(int i=0; i<e; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    } 
    int m;
    cout << "Enter number of colors: ";
    cin >> m;

    graphColoring(graph, n, m);
    if(solutions == 0) cout << "Graph cannot colored as desired using given number of colors" << endl;
    else cout << "Total number of ways: " << solutions << endl;

    cout << "\nChromatic Number: " << chromaticN(graph, n, m) << endl;
}



/*
n = 10
e = 15
0 1
0 4
0 5
1 2
1 6
2 3
2 8
3 4
3 9
4 7
5 8
5 9
6 7
6 9
7 8

n = 4
e = 5
0 1
0 2
0 3
1 2
2 3

*/