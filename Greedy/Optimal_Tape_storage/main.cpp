#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

float calc_MRT(vector<int> T) {
    int n = T.size();
    vector<int> cost;
    int sum = 0;
    for (int i = 0; i < n;i++) {
        sum += T[i];
        cost.push_back(sum);
        cout << T[i] << " ";
    }
    cout << endl;

    float total_cost = 0;
    for (int i = 0; i < cost.size(); i++) {
        total_cost += cost[i];
    }

    float MRT = total_cost / n;

    return MRT;
}

void store_tape() {
    int m;
    cout << "Enter number of tapes: ";
    cin >> m;

    int n;
    cout << "Enter number of programs: ";
    cin >> n;
    int L[n];
    cout << "Enter Length of all the programs: ";
    for (int i = 0; i < n; i++) {
        cin >> L[i];
    }

    sort(L, L + n);

    vector<int> T[m];
    int j = 0;
    for(int i=0; i<n; i++) {
        T[j].push_back(L[i]);
        j++;
        if(j>=m) j=0;
    }

    float MRT;
    cout << endl;
    for(int i=0; i<m; i++) {
        cout << "Order of programs store in Tape" << i+1 << " : ";
        MRT = calc_MRT(T[i]); 
        cout << "MRT for Tape" << i+1 << " : " << MRT << endl;
        cout << endl;
    }

}

int main() {
    store_tape();
}