#include<iostream>
#include<string>

using namespace std;

/*
* LCS - Longest common subsequence
* LCS of 2 sequence is not unique
& Brute force requires Exponential time to solve LCS problem
! Time complexity: O(2ᵐ)
& DP solves LCS in quadratic time
& Quadratic means the runtime of the algorithm is directly proportional to the square of the size of the input
& Steps:
^ Create m(rows) x n (columns) matrix whose 1st row and 1st columns is filled with 0
^ For int i=1 to m and j=1 to n
^ If (i-1)th element of X and (j-1)th Y are equal 
^ fill (i,j)th box with (i-1,j-1)th + 1 
^ Else with max of (i-1, j)th and (i, j-1)th (In this case, if both values are equal, we use arrows to the previous rows(upward))
! Time Complexity: O(m*n)
! Auxiliary Space: O(m*n)
*/

string** LCS(string x, string y) {
    int m = x.size();
    int n = y.size();
    int dp[m+1][n+1];
    string **arrows;
    arrows = new string*[m];
    for(int i=0; i<m; i++) arrows[i] = new string [n];
    
    for(int i=0; i<=m; i++) dp[i][0] = 0;
    for(int j=1; j<=n; j++) dp[0][j] = 0;

    for(int i=1; i<=m; i++) {
        for(int j=1; j<=n; j++) {
            if(x[i-1] == y[j-1]) {
                dp[i][j] = dp[i-1][j-1] +1;
                arrows[i-1][j-1] = "↖︎";
            } else {
                if(dp[i-1][j] >= dp[i][j-1]) {
                    dp[i][j] = dp[i-1][j];
                    arrows[i-1][j-1] = "↑";
                } else {
                    dp[i][j] = dp[i][j-1];
                    arrows[i-1][j-1] = "←";
                }
            }
        }
    }

    return arrows;  
}

// !Time Complexity: O(m+n)
int count=0;
void Print_LCS (string **arrows, string x, int i, int j) {
    if(i==-1 || j==-1) {
        cout << "\nLongest Common Sequence: "; 
        return;
    } 
    if(arrows[i][j] == "↖︎") {
        Print_LCS (arrows, x, i-1, j-1);
        cout << x[i] << " ";
    } 
    else if(arrows[i][j] == "↑") Print_LCS (arrows, x, i-1, j);
    else if(arrows[i][j] == "←") Print_LCS (arrows, x, i, j-1);
}

int main() {

    string x;
    cout << "Enter string1 : ";
    getline(cin, x);

    string y;
    cout << "Enter string2: ";
    getline(cin, y);
    
    string **arrows = LCS(x, y);
    int m = x.size();
    int n = y.size();
    Print_LCS(arrows, x, m-1, n-1);
    cout << "\nLength of common subsequence: " << count << endl;
    
    return 0;
}

/*

10010101
010110110

1010011
01110101

AGGTAB
GXTXAYAB
*/
