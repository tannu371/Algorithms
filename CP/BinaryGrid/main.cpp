#include<bits/stdc++.h>
using namespace std;

//  Minimum Number of Flips to Make Binary Grid Palindromic II - Return the minimum number of cells that need to be flipped to make all rows and columns palindromic, and the total number of 1's in grid divisible by 4

int minFlips(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    int ans=0;

    // If number of element is less than 4 convert all ones to zeros.
    if(m*n<4) {
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                ans += grid[i][j];
            }
        }
        return ans;
    }

    // Count number of ones in  4 elements as it should be palindromic row wise as well as columnwise and make all 4 either 0 or 1.
    int count;
    for(int i=0, j=m-1; i<j; i++, j--) {
        for(int k=0, l=n-1; k<l; k++, l--) {
            count = (grid[i][k] + grid[i][l] + grid[j][l] + grid[j][k]);
            ans+= min(count, 4-count);
        }
    }

    // Count number pairs which are not equal and number of pairs of ones.
    int notEq=0, pair1=0;
    // when odd number of row count in middle row.
    if(m%2) {
        for(int i=0, j=n-1;i<j; i++, j--) {
            if(grid[m/2][i]==grid[m/2][j]) {
                pair1+=grid[m/2][i];
            } else notEq++;
        }
    }
    // when odd number of columns count in middle column.
    if(n%2) {
        for(int i=0, j=m-1;i<j; i++, j--) {
            if(grid[i][n/2]==grid[j][n/2]) {
                pair1+=grid[i][n/2];
            } else notEq++;
        }
    }
    
    // These must need to equal.
    ans += notEq;

    // If number of pairs of 1 is not divisible by 2 means we have 2 extra ones (number of ones % 4 = 2), we need to convert those to zeros if notEq = 0 as if it is atleast 1 that can we converted to 1 and we will have required grid.
    if(pair1%2) {
        if(notEq==0) ans+=2;
    }

    // If we have odd number of rows and odd number of columns means that middle one element must be 0 to be divisible by 4.
    if(m%2 && n%2) ans+=grid[m/2][n/2];

    return ans;
}

int main() {

}