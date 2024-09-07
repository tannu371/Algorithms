#include<bits/stdc++.h>
using namespace std;

// Find the Count of Numbers Which Are Not Special - Having exactly two factor expect itself are Special NUmbers. 

/*
& Sieve of Eratosthenes - Very efficient way to generate all prime numbers upto a given limit.
*/

int nonSpecialCount(int l, int r) {
    // Finding number upto which prime is required.
    int n=2;
    while(n*n<r) n++;

    // Boolean array to store if a number is prime or not from(0 to n).
    bool isPrime[n+1];

    // Initialize to false for 0 and 1 indicating non-prime and to true from 2 to n indicating potential primes.
    isPrime[0] = false;
    isPrime[1] = false;
    for(int i=2; i<=n; i++) {
        isPrime[i] = true;
    }

    // Iterate from 2 to n, if the number is still marked true, mark all it's multiple as false.
    for(int i=2; i<=n; i++) {
        if(isPrime[i]==true) {
            int m=2;
            while(m*i<=n) {
                isPrime[m*i] = false;
                m++;
            } 
        }
    }

    // Collecting/Storing primes.
    // Squaring square of prime as well, as these are special numbers. 
    vector<int> primes;
    vector<int> primeSq;
    for(int i=2; i<=n;i++) {
        if(isPrime[i]) {
            primes.push_back(i);
            primeSq.push_back(i*i);
        } 
    }

    // Caculating number laying in range[l, r]
    int range = r-l+1;

    // Counting special numbers if it is in range[l, r]
    int specialCount=0;
    for(int i=0; i<primeSq.size(); i++) {
        if(primeSq[i] <= r && primeSq[i] >=l) specialCount++;
    }
    
    // Calculating non special numbers
    int nonSpecialCount = range-specialCount;

    return nonSpecialCount;
}

int main() {

}