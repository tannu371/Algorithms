#include<bits/stdc++.h>
using namespace std;

// Shortest Distance After Road Addition Queries I - . Initially, there is a unidirectional road from city i to city i + 1 for all 0 <= i < n - 1. queries[i] = [ui, vi] represents the addition of a new unidirectional road from city ui to city vi.Return an array answer where for each i in the range [0, queries.length - 1], answer[i] is the length of the shortest path from city 0 to city n - 1 after processing the first i + 1 queries.

// ! Shortest distance apply bfs.

vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
    vector<int> ans;

    int qLength = queries.size();
    vector<int>graph[n];

    for(int i=0; i<n-1; i++) {
        graph[i].push_back(i+1);
    }

    for(int i=0; i<qLength; i++) {
        graph[queries[i][0]].push_back(queries[i][1]);
        vector<int> Visited(n,0);

        // ! Use queue access front element and push all adjacent element which are not seen before with it pathLength, it would be minimum as we reached them first first time
        queue<pair<int, int>>q;

        // ! Take care of which element to push as start node and mark visited as 1 for  start node.
        q.push({0,0});
        Visited[0] = 1;

        while(!q.empty()) {
            int u = q.front().first;
            int pL = q.front().second;
            q.pop();

            // ! break from loop if desired destination is reached.
            if(u==n-1) {
                ans.push_back(pL);
                break;
            }

            // Visit all adjacent node of current node.
            for(int v:graph[u]) {
                if(!Visited[v]) {
                    // ! If a node is not seen before push it and mark Visited as 1.
                    q.push({v, pL+1});
                    Visited[v] = 1;
                }
                // if a node is already visited means it has been pushed to queue and soon it's childern will get expanded and visiting them once more suggets that we get another path form source node to that node which is greater than smallest path.
            }
        }
    }
    return ans;
}

int main() {
    vector<vector<int>> q {{1, 4},{0,2}};
    vector<int> ans = shortestDistanceAfterQueries(6, q);

    for(int i=0; i<ans.size(); i++) cout << ans[i]<<" ";
}