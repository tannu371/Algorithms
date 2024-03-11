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

void fractionalKnapsack(int n, int*p, int*w, int m) {

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
    cout << "Weight\t" << "Fraction\t" << "Profit" << endl;
    for(int j=0; j<i+1; j++) {
        cout << w[j] << x[j] << p[j]*x[j] << endl;
        max_profit += p[j] * x[j];
    } 

    cout << "Maximum Profit: "<< max_profit;
}

int main() {
    int n;
    cout << "Enter number of objects: ";
    cin >> n;

    int p[n];
    cout << "Enter profit of objects: ";
    for (int i = 0; i < n; i++) cin >> p[i];

    int w[n];
    cout << "Enter weight of objects: ";
    for (int i = 0; i < n; i++) {
        cin >> w[i];
        if (w[i] < 0) {
            cerr << "Weight of object can't be negative" << endl;
            return;
        }
    }

    int m;
    cout << "Enter capacity of Knapsack: ";
    cin >> m;
    
    fractionalKnapsack(n, p, w, m);

    return 0;

}

// n=7
// 2 3 5 7 1 4 1
// 10 5 15 7 6 18 3
// m=15