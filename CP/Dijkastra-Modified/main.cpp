#include<bits/stdc++.h>
using namespace std;

// Second minimum time to reach from city 1 to city n : bi-directional connected graph. (modified dijkstra - single source shortest path).
int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
    
    // Adjacency List Graph
    vector<int> adj_city[n];
    // ! use for(auto elem : container) instead of range based for loop when there's no use of index as such.
    for (auto e : edges) {
        adj_city[e[0]-1].push_back(e[1]-1);
        adj_city[e[1]-1].push_back(e[0]-1);
    }

    // & Priority queue store {time_taken, destination} sorted in increasing order of first element(time_taken)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // & Keep track of number of time a city is pushed in priority queue
    int freq[n];
    for(int i=0; i<n; i++) freq[i]=0;

    // ! Equal weight ensure we get min time path when we first encountered the city, frequecy decide which min we encountered (1st or 2nd).

    // & Keep track of minimum Time Taken so that we don't reach same city multiple times with same time
    int tt[n];
    for(int i=0; i<n; i++) tt[i] = INT_MAX;
    tt[0] = 0;

    // Pushing Source node
    pq.push({0, 0});
    freq[0]++;

    while(!pq.empty()) {
        int time_elapsed = pq.top().first;
        int u = pq.top().second;

        // & Calculting time elapsed before moving to next city since signal is on for change minutes and off for next change minutes
        int turns = time_elapsed/change;
        // At 0, 2, 4, .... - green Signal and At 1, 3, 5, .... - red Signal
        if(turns%2 !=0) {
            time_elapsed = change*(turns+1);
        }

        for(auto v : adj_city[u]) {
            if(tt[v] != time_elapsed + time && freq[v] < 2) {
                // ! Return time taken to reach destination city (n-1) when we encountere (n-1) 2nd time.
                if(v==n-1 && freq[v] == 1) return time_elapsed + time;
                
                // ! Updating frequency and time_taken for city v and pushing it into priority queue.
                freq[v]++;
                tt[v] = time_elapsed + time;
                pq.push({time_elapsed + time, v});
            }
        }

        // poping the topmost city as it's adjacent city has been visited.
        pq.pop();
    }

    return -1;
}

    int main() {
        
    }