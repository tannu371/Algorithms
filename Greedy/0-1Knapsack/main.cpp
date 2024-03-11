// select in decreasing order of p/w
#include<iostream>

using namespace std;

void interchange(int a[], int i, int j) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

int partition(int p[], int w[], int low, int high) {
    int pIndex = low;
    float pivot = float(p[pIndex]) / w[pIndex];
    int i = low, j = high;
    while (i < j) {
        while (float(p[i]) / w[i] >= pivot && i < high) i++;
        while (float(p[j]) / w[j] < pivot) j--;
        if (i < j) {
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
    if (low >= high) return;
    int pIndex = partition(p, w, low, high);
    Quick_Sort(p, w, low, pIndex - 1);
    Quick_Sort(p, w, pIndex + 1, high);
}

void knapSack0_1(int n, int*p, int*w, int m) {
    Quick_Sort(p, w, 0, n - 1);

    float x[n];
    for (int i = 0; i < n; i++) x[i] = 0;
    float U = m;
    int i = 0;
    while (i < n) {
        if ((i + 1) < n && U - w[i] < w[i + 1]) break;
        x[i] = 1;
        U -= w[i];
        i++;
    }
    while(i<n) {
        if(w[i] > U) break;
        i++;
    }
    i--;
    x[i] = 1;

    float max_profit = 0;
    cout << "Profit\t" << "Weight" << endl;
    for (int j = 0; j < i+1; j++) {
        if(x[j] == 1) {
            cout << p[j] * x[j] << '\t' << w[j] << endl;;
            max_profit += p[j] * x[j];
        }
    }

    cout << "Maximum Profit: " << max_profit;
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
            cerr << "Weight of object cannot be negative." << endl;
            exit(0);
        }
    }

    int m;
    cout << "Enter capacity of Knapsack: ";
    cin >> m;

    knapSack0_1(n, p, w, m);
}

// 60 100 120
// 10 20 30
// 40