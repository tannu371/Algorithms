#include<bits/stdc++.h>
using namespace std;

// Number of Bit Changes to Make Two Integers Equal - Change only 1 to 0, return -1 if not possible

// ! Decimal to Binary Conversion
vector<int> decimalToBinary(int a) {
    vector<int> x;
    while(a>0) {
        x.push_back(a%2);
        a = a>>1;
    }
    return x;
}

int minChanges(int n, int k) {
    vector<int> a = decimalToBinary(n);
    vector<int> b = decimalToBinary(k);
    int nn = a.size();
    int nk = b.size();

    // Number of bits in k is greater than number of bits in n implies we need some extra ones at the leftside in binary of n to get k, which is unacceptable task, therfore we return -1.
    if(nk>nn) return -1;

    // Number of bits in k is less than number of bits in n implies we need to convert  some of the ones to zeros in leftside of binary of n  to get k.
    while(nk<nn) {
        b.push_back(0);
        nk++;
    }
    
    // If one are converted to zero which is required operation we're increasing the count and if any of the zero bit is converted to one which is unacceptable we're returning -1.
    int count=0;
    for(int i=0; i<nn; i++) {
        if((a[i]==1) && (b[i]==0)) count++;
        if((a[i]==0) && (b[i]==1)) return -1;
    }

    return count;
}

// ! Instead of first converting decimal to binary we can use check required condition bit by bit as in each iteration.

int minChanges(int n, int k) {
    // We will check bit by bit if n can be converted to k by doing required operation only.
    int a, b;

    int count=0;
    while(!(n==0 && k==0)) {
        // Store Reminder, which is leftmost bit in binary representation
        a = n%2;
        b = k%2;

        // Divide in each iteration
        n/=2;
        k/=2;

        // If corresponding bit on n and k are equal we are not needed count operation.
        if(a==b) continue;
        // Since only ones can be changed to zeros, if we find that we need to change zero to one we return -1.
        if((a==0)&&(b==1)) return -1;
        // ones are changed to zero we increment the counte as it is required operation.
        else count++;
    }
    return count;
}

int main() {
    
}