#include <iostream>

using namespace std;

/*
Minimum cost path from vertex s in V₁ to vertex t in V𝚔
c[i, j] = cost of edge <i,j>
cost(i, j) = min cost from j in Vℹ to t
bcost(i, j) = min cost from s to j in Vℹ 
Forward Approach : cost(i, j) = min {c[j, l] + cost(i+1, l)}
Backward Approach : bcost(i, j) = min {bcost(i-1, l) + c[l, j]}
Time Complexity : ϴ(|V| + |E|)    (graph is represented as adjacency list)
*/ 

int main() {

}
