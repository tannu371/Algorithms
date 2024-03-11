#include<iostream>
#include<vector>

using namespace std;

/*
* Knuth-Morris-Pratt Pattern Matching Algorithm
& Time Complexity : O(n+m)
& Auxiliary Space: O(m)
! lps : longest proper prefix suffix
*/ 

int countMatchingSubarrays(vector<int>& text, vector<int>& pattern) {
    int n = text.size();
    int m = pattern.size();
    
    vector<int>lps(m,0);
    int len = 0;
    int k=1;
    while(k<m) {
        if(pattern[len] == pattern[k]) {
            len++;
            lps[k] = len;
            k++;
        } else {
            if(len != 0) {
                len = lps[len-1];
            } 
            else {
                lps[k] = 0;
                k++;
            } 
        }
    }
    
    cout << endl;
    
    int count=0;
    int i=0, j=0;
    while(i<n) {
        if(text[i] == pattern[j]) {
            i++, j++;
            if(j==m) {
                count++;
                j = lps[j-1];
            } 
        } 
        else {
            if(j > 0) j = lps[j-1];
            else i++;
        }  
    }
    
    return count;
}

int main() {
    
}