#include<iostream>

using namespace std;

void interchange(int a[], int i, int j) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

int partition(int p[], int w[], int low, int high) {
    int pIndex = low;
    float pivot = float(p[pIndex])/w[pIndex];
    int i=low, j=high;
    while(i<j) {
        while(float(p[i])/w[i] >= pivot && i<high) i++;
        while(float(p[j])/w[j] < pivot) j--;
        if(i<j) {
            interchange(p, i, j);
            interchange(w, i, j);

            j--;
        }
    }
    interchange(p, pIndex, j);
    interchange(w, pIndex, j);

    pIndex = j;

    return pIndex;
}

void Quick_Sort(int p[], int w[], int low, int high) {
    if(low>=high) return;
    int pIndex = partition(p, w, low, high);
    Quick_Sort(p, w, low, pIndex-1);
    Quick_Sort(p, w, pIndex+1, high);
}

// Maximize profit 
// select in decreasing order of p/w
// Time complexity: O(nlog₂n)

void Knapsack() {
    int n;
    cout << "Enter number of objects: ";
    cin >> n;

    int w[n];
    cout << "Enter weight of objects: ";
    for(int i=0; i<n; i++) cin >> w[i];

    int p[n];
    cout << "Enter profit of objects: ";
    for(int i=0; i<n; i++) cin >> p[i];
    
    int m;
    cout << "Enter capacity of Knapsack: ";
    cin >> m;

    // decreasing order of profit/weight
    Quick_Sort(p, w, 0, n-1);       

    float x[n];
    for(int i=0; i<n; i++) x[i]=0;
    float U = m;
    int i=0;
    while(i<n) {
        if(w[i] > U) break;
        x[i] = 1;
        U -= w[i];
        i++;
    }
    if(i<=n) x[i] = U/w[i];

    float max_profit = 0;
    for(int i=0; i<n; i++) max_profit += p[i]*x[i];

    cout << "Maximum Profit: "<< max_profit;
}

void display_array(int arr[], int size) {
    for(int i=0; i<size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}



int main() {
    
    Knapsack();

    return 0;

}

// n=7
// 2 3 5 7 1 4 1
// 10 5 15 7 6 18 3
// m=15