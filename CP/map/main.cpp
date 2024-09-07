#include<bits/stdc++.h>
using namespace std;

// Kth Distinct String in an Array

/* 
! map store ordered key(ASCII value). Unordered_map store randomly. Thus we careful when you are using map.
& for(auto e : mp) or it = mp.begin() while(it !=mp.end())
& e.first e.second it->first it->second 
*/

string kthDistinct(vector<string>& arr, int k) {
    
    // Storing count of strings. Note these get stored randomly and not in odered in which they appear first in the array.
    // ! No need of iterating from 0 to n (range based for loop). Instead access element in each iteration of for loop. If you are not using index values inside for loop.
    unordered_map<string, int> mp;
    for(string s: arr) {
        mp[s]++;
    }

    // Iterating over array it-self to get order in which they appear in the array (instead of iterating over map).
    // ! No need of extra variable to get kth string instead u can decrement value of k and return if it's zero.
    for(string s: arr) {
        if(mp[s]==1 && --k==0) return s;
    }

    return "";
}

int main() {

}