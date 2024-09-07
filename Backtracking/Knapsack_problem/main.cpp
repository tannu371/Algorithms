#include<iostream>
using namespace std;

struct Object {
    int id;
    float w;
    float p;
};

bool isValid(Object* obj, int* seq, int i, int w) {
    int sum = 0;
    for(int j=0; j<=i; j++) {
        if (seq[j]) sum += obj[j].w;
    }
    if(sum<=w) return true;
    return false;
}



void KnapsackBacktrack(Object* obj, int n, int w, int* index=NULL, int i=0) {
    static int maxSum = 0;
    if(index==NULL) {
        index = new int[n];
    }
    if(i==n) {
        int sum = 0;
        for (int j = 0; j < n; j++) sum += obj[j].p;
        if(sum > maxSum && sum<=w) {
            maxSum = sum;
            cout << "id\t" << "Weight\t" << "Profit" << endl;
            for (int j = 0; j < n; j++) {
                if (index[j]) {
                    cout << obj[j].id << "\t" << obj[j].w << "\t" << obj[j].p << endl;
                }
            }
            cout << endl;
            cout << "MaxProfit: " << maxSum << "\n" << endl;
        } 
    }

    for(int j=i; j<n;j++) {
        if (isValid(obj, index, i, w)) index[j] = 1; df gj 
        KnapsackBacktrack(obj, n, w, index, i + 1);
        index[j] = 0;
    }

}

int main() {
    int n;
    cout << "Ente number of objects: ";
    cin >> n;

    Object objects[n];
    for(int i=0;i<n; i++) {
        objects[i].id = i + 1;
        cout << "Enter weight and profit of O"<<i+1<<" : ";
        cin >> objects[i].w >> objects[i].p;
        if(objects[i].w <=0 ) {
            cout << "Weight of objects cannot be zero or negative." << endl;
        }
    }

    float m;
    cout << "Enter maximum capacity of KnapSack: ";
    cin >> m;

    KnapsackBacktrack(objects, n, m);

}