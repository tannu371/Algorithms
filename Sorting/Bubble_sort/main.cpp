#include<iostream>

using namespace std;

void interchange(int a[], int i, int j) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

// increasing order
// & Time Complexity : O(n²)
void bubble_sort(int* a, int n) {
    for(int i=n-2; i>=0; i--) {
        for(int j=0; j < i; j++) {
            if(a[j] > a[j+1]) {
                interchange(a, j, j+1);
            }
        }
    }
}

int main() {

}