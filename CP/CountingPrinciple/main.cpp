#include<bits/stdc++.h>
using namespace std;

// Count number of Team - 3 members i<j<k such that ratings are strictly increasing or strictly decreasing.

/*
! Using Counting Principle
& Stand in middle(2nd person) and possible number of teams are leftSmall*rightBig when strictly increasing and leftBig*rightSmall when strictly decreasing.
*/

int numTeams(vector<int>& rating) {
    int n=rating.size();
    int teams=0;

    // Fixing middle person in each iteration.
    for(int i=1; i<n; i++) {
        int leftSmall=0, leftBig=0, rightSmall=0, rightBig=0;
        
        // Counting smaller or lagerer than middle person on left side.
        for(int j=0; j<i; j++) {
            if(rating[j]<rating[i]) leftSmall++;
            else if(rating[j]>rating[i]) leftBig++;
        }

        // Counting smaller or lagerer than middle person on right side.
        for(int j=i+1; j<n; j++) {
            if(rating[i] > rating[j]) rightSmall++;
            else if(rating[i] < rating[j]) rightBig++;
        }

        // Updating number of teams for each iteration using counting principle.
        teams+=(leftSmall*rightBig+ leftBig*rightSmall);
    }
    return teams;
}

int main() {

}