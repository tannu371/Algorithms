#include<bits/stdc++.h>
using namespace std;

// Filling Bookcase Shelves - return minimum possible height of shelf if all books are placed in order.

/*
!dp
! 2D : Space Complexity O(n);
& 1. First write recursive code - Note that 1st value we get from recurrsive code is from last step of recursion.
& 2. Convert into dp by memoizing it.
*/

class Solution {
    // constant values required to solve 
    vector<vector<int>> books;
    int shelfWidth;
    vector<vector<int>> dp;
    
public:
    // Keep track of changing values which are required in solving the problem in variables.
    int minHeight(int currIndex, int currWidth, int maxHeight) {
        // Memoization.
        if(dp[currIndex][currWidth] != -1) return dp[currIndex][currWidth];

        // 1st write base case (think of when you can actually predict a solution).
        if(currIndex==books.size()-1) {
            if(currWidth >= books[currIndex][0]) return dp[currIndex][currWidth] =  max(maxHeight, books[currIndex][1]);
            return dp[currIndex][currWidth] = (maxHeight + books[currIndex][1]);
        }

        // According to last return value write code for possible condition.
        // Space left - 2 possibilities arises put on next shel or put on current shelf.
        if(currWidth - books[currIndex][0] >=0) return dp[currIndex][currWidth] =  min(maxHeight + minHeight(currIndex+1, shelfWidth-books[currIndex][0], books[currIndex][1]), minHeight(currIndex+1, currWidth- books[currIndex][0], max(maxHeight, books[currIndex][1])));
        // No space left for current book just keep on next shelf.
        return dp[currIndex][currWidth] = maxHeight + minHeight(currIndex+1, shelfWidth-books[currIndex][0], books[currIndex][1]);
    }

    int minHeightShelves(vector<vector<int>>& books, int shelfWidth){
        
        this->books = books;
        this->shelfWidth = shelfWidth;
        vector<int> w(shelfWidth+1, -1);
        vector<vector<int>>dp (books.size(), w);
        this->dp = dp;

        return minHeight(0, shelfWidth, 0);
    }
};

int main() {

}