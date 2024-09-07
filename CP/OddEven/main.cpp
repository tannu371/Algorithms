#include<bits/stdc++.h>
using namespace std;

// Vowels Game in a String - Alice remove substring containg odd number of vowels and Bob substring containg even number of vowels. Return true if Alice win.

/*
! Odd + Even = Odd
! Odd + Odd = Even
! Even + Even = Even
*/

bool doesAliceWin(string s) {
    int n = s.length(); 
    int odd=0;
    int even=0;
    int count=0;
    
    s+='b'; // Adding a extra constant to check for value of count after iterating over entire string.
    for(int i=0; i<=n; i++) {
        if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u') count++;
        else {
            if(count!=0) {
                if(count%2==0) even++;
                else odd++;
                count=0;
            }   
        }
    }

    // Check value of count after entire string is passed.
 /* 
    if(count!=0) {
        if(count!=0) {
            if(count%2==0) even++;
            else odd++;
        }
    } 
*/

    while(even>0) {
        // Removing odd from even instance creates a odd instace.
        odd++, even--;
        // Removing even instance from even instance or odd instance doesn't effect number of odd instances.
        even--;
    }
    
    if(even<0||odd>0) return true;
    return false;
}

// ! No need to do all this, observe carefully, u will realize alice wins even if there is atleast one vowel in the substring.

bool doesAliceWin(string s) {
    for(int i=0; i<s.length(); i++) {
        if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u') return true;
    }

    return false;
}

int main() {

}