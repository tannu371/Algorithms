#include<bits/stdc++.h>
using namespace std;

// Minimum Swaps to Group All 1's Together II - Given binary circular array.

/*
! Sliding Window
*/

int minSwaps(vector<int>& nums) {
    int n = nums.size();

    // ! Fixed window length
    // Calculate window length
    int windowLength=0;
    for(int i=0; i<n; i++) {
        windowLength+=nums[i];
    }

    // Calculating ones in first window starting at index 0.
    int OnesInWindow[n];
    OnesInWindow[0]=0;
    for(int i=0; i<windowLength; i++) {
        OnesInWindow[0]+=nums[i];
    }

    //! Since it is circular array, we push window length - 1 number of elements to get all possible window.
    for(int i=0; i<windowLength-1; i++) {
        nums.push_back(nums[i]);
    }

    // Calculate Ones in all windows that we get from 2nd element to last element.
    for(int i=1; i<n; i++) {
        OnesInWindow[i] = OnesInWindow[i-1] - nums[i-1] + nums[i+windowLength-1]; 
    }

    //! Finding window with minimum number of zeros which is required number of operations to put all ones together.
    int ans = n;
    for(int i=0; i<n; i++) {
        ans = min(ans, (windowLength-OnesInWindow[i]));
    }

    return ans;
}

int main() {

}