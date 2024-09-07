#include<bits/stdc++.h>
using namespace std;

// Check if the Rectangle Corner Is Reachable - Without touching or intersecting circle and without touching the rectange except at origin and destination.

/*
! Disjoint Union Set
& Initialize parent
& Write recursive find set function 
& Write union set function using find set funciton

! circle touching or intersecting c1c2 <= r1+r2
& c1c2 = sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1)
*/

// Finding parent (find set)
int findParent(int* parent, int v) {
    if (parent[v] == v) return v;
    return findParent(parent, parent[v]);
}

// Make parent equal (union set)
void unionSet(int u, int v, int*parent) {
    int a = findParent(parent, u);
    int b = findParent(parent, v);
    if(a!=b) parent[a] = b;
}

bool canReachCorner(int X, int Y, vector<vector<int>>& circles) {
    int n = circles.size();

    // Initializing parent (set). n is the start node(origin) and n+1 is the destination node(X,Y)
    int parent[n+2];
    for(int i=0; i<n+2; i++) {
        parent[i] = i;
    }

    // Use long long for values of xi, yi, ri since range is 10^9 and we will sqaure values later on.
    long long x1, y1, r1;
    long long x2, y2, r2;

    for(int i=0; i<n; i++) {
        x1 = circles[i][0];
        y1 = circles[i][1];
        r1 = circles[i][2];

        // If circle touches down or right we unify it with node n(origin) 
        if((y1-r1<=0) || (x1+r1>=X)) {
            unionSet(i, n, parent);
        } 

        // If circle touches up or left we unify it with node n+1(X,Y)
        if((y1+r1>=Y) || (x1-r1<=0)) {
            unionSet(i, n+1, parent);
        }

        // Iterating over all previously visited circle if it is intersecting or touching with current circle.
        for(int j=0; j<i; j++) {
            x2 = circles[j][0];
            y2 = circles[j][1];
            r2 = circles[j][2];

            // Don't use int to store value of c1c2 i.e, distance between 2 centre as it can be floating point number, however use can strore in float.
            if(sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1))<=(r1+r2)) {
                unionSet(i, j, parent);
            }
        }
    }
    
    // If parent of origin node n equals parent of destination node n+1, then there is no path from origin to destination
    return findParent(parent, n) != findParent(parent, n+1);
}

int main() {

}