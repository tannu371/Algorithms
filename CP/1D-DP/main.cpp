#include<bits/stdc++.h>
using namespace std;

// Filling Bookcase Shelves - return minimum possible height of shelf if all books are placed in order.
// ! 1D : Space Complexity O(n);

int minHeightShelves(vector<vector<int>>& books, int shelfWidth){
    int n = books.size();
    vector<int> dp(n+1, INT_MAX);
    dp[0] = 0;

    int j;
    for(int i=1; i<=n; i++) {
        // keep track of changing values require to solve the problem in variables.
        int currWidth = 0;
        int maxHeight = 0;
        // Placing ith book at required place.
        for(j=i; j>0; j--) {
            currWidth += books[j-1][0];
            if(currWidth > shelfWidth) break;
            maxHeight = max(maxHeight, books[j-1][1]);
            //! Update dp[i] for each dp[j-1].
            dp[i] = min((maxHeight + dp[j-1]), dp[i]);
        }
    }

    return dp[n];
}

int main() {

}