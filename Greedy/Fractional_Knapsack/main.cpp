#include<iostream>
#include<algorithm>

using namespace std;

// Maximize profit 
// select in decreasing order of p/w
// Time complexity: O(nlog₂n)

struct Object{
    int id;
    float weight;
    float profit;
};

bool compare(Object &o1, Object &o2) {
    return (o1.profit/o1.weight > o2.profit/o2.weight);
}

void fractionalKnapsack() {

    int n;
    do {
        cout << "Enter number of objects: ";
        cin >> n;
    } while(n<=0);
    

    Object* objs = new Object[n];
    float w, p;
    for(int i=0; i<n; i++) {
        cout << "Enter weight and profit of object "<< i+1 << " : ";
        cin >> w >> p;
            
        while (w <= 0) {
            cout << "Weight of object cannot be negative or zero." << endl;
            cout << "Re-enter weight and profit of object " << i+1  << " : ";
            cin >> w >> p;
        } 

        objs[i].id = i+1;
        objs[i].weight = w;
        objs[i].profit = p;
    }

    sort(objs, objs+n, compare); 

    float m;
    cout << "Enter capacity of Knapsack: ";
    cin >> m;

    float x[n];
    for(int i=0; i<n; i++) x[i]=0;
    float U = m;
    int i=0;
    while (i<n && objs[i].weight < U) {
        x[i] = 1;
        U -= objs[i].weight;
        i++;
    }
    if(i<n) x[i] = U/objs[i].weight;

    float max_profit = 0;
    cout << "\nId\tWeight\tProfit\tp/w\tFraction taken" << endl;
    for(int j=0; j<=i; j++) {
        w = objs[j].weight;
        p = objs[j].profit;
        cout << objs[j].id << "\t" << w << "\t" << p << '\t' << p/w << '\t' << x[j] << endl;
        max_profit += objs[j].profit * x[j];
    } 

    cout << "\nMaximum Profit: "<< max_profit;
}

int main() {
    fractionalKnapsack();
}

// n=7
// 2 3 5 7 1 4 1
// 10 5 15 7 6 18 3
// m=15