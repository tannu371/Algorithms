#include<bits/stdc++.h>
using namespace std;

// Range Sum of Sorted Subarray Sums - computed the sum of all non-empty continuous subarrays from the array and then sorted them in non-decreasing order, creating a new array of n * (n + 1) / 2 numbers.Return the sum of the numbers from index left to index right (indexed from 1), inclusive, in the new array. Since the answer can be a huge number return it modulo 109 + 7.

int rangeSum(vector<int>& nums, int n, int left, int right) {
    int m = 1000000007;

    // ! Instead of using prefixSum we can directly calculate sum between two pointers i and j.
    for(int i=0; i<n; i++){
        int sum = nums[i];
        for(int j=i+1; j<n; j++) {
            sum+=nums[j];
            nums.push_back(sum);
        }
    }

    sort(nums.begin(), nums.end());

    long long ans = 0;
    for(int i=left-1; i<right; i++) ans += nums[i];

    return ans%m;
}

int main() {

}