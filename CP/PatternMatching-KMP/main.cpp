#include<bits/stdc++.h>
using namespace std;
 
/* Number of Subarrays That Match a Pattern II 
You are given a 0-indexed integer array nums of size n, and a 0-indexed integer array pattern of size m consisting of integers -1, 0, and 1.
A subarray nums[i..j] of size m + 1 is said to match the pattern if the following conditions hold for each element pattern[k]:
nums[i + k + 1] > nums[i + k] if pattern[k] == 1.
nums[i + k + 1] == nums[i + k] if pattern[k] == 0.
nums[i + k + 1] < nums[i + k] if pattern[k] == -1.
Return the count of subarrays in nums that match the pattern.
*/

/*
! Knuth-Morris-Pratt Pattern Matching Algorithm
& Time Complexity : O(n+m)
& Auxiliary Space: O(m)
! lps : longest proper prefix suffix

& Brute Force Exhaustive Search - O(n*m)
*/ 

int countMatchingSubarrays(vector<int>& text, vector<int>& pattern) {
    int n = text.size();
    int m = pattern.size();
    
    // longest proper prefix which is also a suffix. Proper prefix means entire string is not included.
    // lps of pattern at i stores maximum length of lps from 0 to i.
    vector<int>lps(m,0);
    // keep track of length of lps of previous index.
    int len = 0;
    // lps at k=0 is 0.
    int k=1;
    while(k<m) {
        // pattern at len matches with pattern at k, increment len by 1 assign to lps at k and increment k.
        if(pattern[len] == pattern[k]) {
            len++;
            lps[k] = len;
            k++;
        } else {
            // pattern at len do not match with pattern at k and len not equal to zero, update len by lps at len-1.
            if(len != 0) {
                len = lps[len-1];
            } 
            else {
            // pattern at len do not match with pattern at k and len equal to zero, assign lps at k equal to zero and increment k.
                lps[k] = 0;
                k++;
            } 
        }
    }
    
    // Match text and pattern
    int count=0;
    int i=0, j=0;
    while(i<n) {
        // If text and pattern matches, increment i and j.
        if(text[i] == pattern[j]) {
            i++, j++;
            // If j=m which is length of pattern, increment count and rest j to lps[j-1] and these number of characters will be skipped.
            if(j==m) {
                count++;
                j = lps[j-1];
            } 
        }
        // If text and pattern do not match, 
        else {
            // If j is greater than zero lps[j-1] length of characters need not be matched. 
            if(j > 0) j = lps[j-1];
            // If j equal to zero means there's no match at i so increment i.
            else i++;
        }  
    }
    
    return count;
}

int main() {
    
}