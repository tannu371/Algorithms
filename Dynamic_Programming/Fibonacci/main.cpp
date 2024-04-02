#include<iostream>

using namespace std;

int f(int i, bool* is_computed=NULL, int* F=NULL) {
    if(i<0) {
        do {
            cout << "Enter non-negative integer only: ";
            cin >> i;
        } while(i<0);
    }
    if(F == NULL) {
        F = new int[i];
        is_computed = new bool[i];
        for(int j=0; j<i; j++) is_computed[j]=false; 
    }

    if(i<2) return i;
    if(is_computed[i]) return F[i];
    F[i] = f(i - 1, is_computed, F) + f(i - 2, is_computed, F);
    is_computed[i] = true;
    return F[i];
}

int main () {
    int i;
    cout << "Enter non-nagative integer whose fibonacci is to be calculted: ";
    cin >> i;
    cout << "Fibonacci of " << i << " is: " << f(i);

    return 0;
}