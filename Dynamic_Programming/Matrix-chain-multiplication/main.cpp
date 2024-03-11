#include<iostream>
#include<utility>
#define INF 999999
using namespace std;

void matrix_chain_order (int* p, int i, int j, int** m, int** s) {
    if(i==j) {
        return;
    }
    m[i][j] = INF;
    int min;
    for(int k = i; k<j; k++) {
        matrix_chain_order(p, i, k, m, s);
        matrix_chain_order(p, k+1, j, m, s);
        min = m[i][k] + m[k+1][j] + p[i - 1] * p[k] * p[j];
        if(m[i][j] > min) {
            m[i][j] = min;
            cout << i << " " << j << " " << m[i][j] << endl; 
            s[i][j] = k;
        } 
    }
    return;
}

void print_order(int** s, int i, int j) {
    if(i>=j) {
        
        return;
    } 
    if(j-i == 1) {
        cout << "( A" << i << "  A" << j << " )";
    }
    int n = s[i][j];
    cout << "( A" << i;
    print_order(s, i, n);
    print_order(s, n + 1, j);
    cout <<  "  A" << j << " )";
}

int main () {
    int n ;
    cout << "Enter number of matrices: ";
    cin >> n;

    pair<int, int> A[n+1];
    int p[n+2];
    for(int i=1; i<n+1; i++) {
        cout << "Enter order of A" << i << " matrix: ";
        cin >> A[i].first >> A[i].second;
        if(i!=1 && A[i].first != A[i-1].second) {
            cerr << "Incorrect input" << endl;
            return -1;
        }
        p[i] = A[i].second;
    }
    p[0] = A[1].first;

    int* m[n+1];
    for(int i=1; i<n+1; i++) {
        m[i] = new int[n + 1];
        m[i][i] = 0;
    } 
    int* s[n+1];
    for (int i = 1; i < n + 1; i++) s[i] = new int[n + 1];
    matrix_chain_order(p, 1, n, m, s);
    cout << "Minimum cost: " << m[1][n] << endl;
    // print_order(s, 1, n);
}