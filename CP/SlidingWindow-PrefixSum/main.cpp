#include<bits/stdc++.h>
using namespace std;

// Count the number of substring with dominant ones - number of ones is greater than or equal to square of number of zeros.

/*
! Sliding window
! PrefixSum
*/

int numberOfSubstrings(string s) {
    int n = s.length();
    int prefixSum[n];
    int count=0;

    // Finding prefix sum
    for(int i=0;i<n;i++){
        if(s[i]=='1') count++;
        prefixSum[i] = count;
    }
    
    // ans store count of valid substrings
    int ans=0;
    // ones and zero will store number of ones and zero in a window [l to r].
    int ones=0, zeros=0;
    // Helper variable to keep track of how many indexes r (upperbound) should we skip.
    int skip;

    // ! Variable window length
    // We focus on window [l to r]
    for(int l=0; l<n; l++) {
        for(int r=l; r<n; r++) {
            skip=0;

            // Count numbers of ones and zeros using prefix sum.
            ones = prefixSum[r]-prefixSum[l];
            if(s[l]=='1') ones += 1;
            zeros = (r-l+1) - ones;

            // If valid substring is found we increment ans for that particular [l to r].
            if(ones>=zeros*zeros) {
                ans++;

                //!  If number of ones is strictly greater than square of zeros we could afford some zeros i.e, some element and it will still be valid substring.
                // Incrementing ans by number of zeros we could affors and skipping that number of elements will decrease time complexity.
                if(ones > zeros*zeros) {
                    skip = sqrt(ones)- zeros;
                    // Checks if we're out of bound when we skip and adjust ans as per condition satisfy.
                    if(skip+r>=n) {
                        ans += (n-r-1);
                    } 
                    else {
                        ans+=skip;
                    }
                }
            }
            // ! If an invalid substring is found, we need at least some ones i.e, some elements to reach a valid substring.
            // Skipping those number of elements will also decrease time complexity.
            else {
                skip = zeros*zeros-ones-1;
            }
            r+=skip;
        }
    }
    return ans;
}

int main() {

}