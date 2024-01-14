#include<iostream>
#include<string>

using namespace std;

// decreasing order

template<typename T>
int partition(T c[], int low, int high) {
    int pIndex = low;
    int i=low, j=high;
    while(i<j) {
        while(c[i] <= c[pIndex] && i<high) i++;
        while(c[j] > c[pIndex]) j--;
        if(i<j) {
            T temp = c[i];
            c[i] = c[j];
            c[j] = temp;
            j--;
        }
    }
    T temp = c[pIndex];
    c[pIndex] = c[j];
    c[j] = temp;
    pIndex = j;
    return pIndex;
}

template<typename T>
void Quick_Sort(T c[], int low, int high) {
    if(low>=high) return;
    int pIndex = partition(c, low, high);
    Quick_Sort(c, low, pIndex-1);
    Quick_Sort(c, pIndex+1, high);
}

// Best case : nlog₂n
// Average case : nlog₂n 
// Worst case : n² (when array is already sorted)

template<typename T>
void display_array(T arr[], int size) {
    for(int i=0; i<size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int a[4]{1,2,3,4};
    Quick_Sort(a, 0, 3);
    display_array(a, 4);

    char c[5]{'a','b','c','d','e'};
    Quick_Sort(c, 0, 4);
    display_array(c, 5);

    string s[5] {"tannu", "talha", "vanshika", "payal", "anupama"};
    Quick_Sort(s, 0, 4);
    display_array(s, 5);

}