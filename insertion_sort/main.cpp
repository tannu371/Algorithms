#include<iostream>

using namespace std;

void insertion_sort(int arr[], int n) {
    for(int i=1; i<n; i++) {
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j] > key) {
            arr[j+1] = key;
            j--;
        }
        arr[j+1] = key;
    }
}

int main() {

}