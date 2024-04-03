#include<iostream>
using namespace std;

struct Object {
    int id;
    float weight;
    float profit;
};

bool Knapsack0_1(int n, Object* objs, int W, int** mat) {
   return false; 
}

int main() {
    int n;
    do {
        cout << "Enter number of items: ";
        cin >> n;
    } while (n <= 0);

    Object* objs = new Object;
    int w, p;
    for (int i = 0; i < n; i++) {
        cout << "Enter weight and profit of object " << i + 1 << " : ";
        cin >> w >> p;

        while (w <= 0) {
            cout << "Weight of object cannot be negative or zero." << endl;
            cout << "Re-enter weight and profit of object " << i + 1 << " : ";
            cin >> w >> p;
        }

        objs[i].id = i + 1;
        objs[i].weight = w;
        objs[i].profit = p;
    }

    int W;
    do {
        cout << "Enter maximum positive integer weight that can be carried in bag: ";
        cin >> W;
    } while(W<=0);
    
    int** idWt = new int*[n+1];
    for(int i=0; i<n; i++) {
        idWt[i] = new int[W];
    } 
    for(int i=0; i<n; i++) {
        idWt[i][0] = 0;
    }
    for(int j=0; j<W; j++) {
        idWt[0][j] = 0;
    }

    Knapsack0_1(n, objs, W, idWt);
}