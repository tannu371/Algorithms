#include<iostream>
#include<utility>
#include<climits>

using namespace std;

void matrix_chain_order(int* p, int i, int j, int** m, int** s) {
    if (i == j) {
        return;
    }
    m[i][j] = INT_MAX;
    int min;
    for (int k = i; k < j; k++) {
        matrix_chain_order(p, i, k, m, s);
        matrix_chain_order(p, k + 1, j, m, s);
        min = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
        if (m[i][j] > min) {
            m[i][j] = min;
            s[i][j] = k;
        }
    }
    return;
}

void print_order(int** s, int i, int j) {
    if (i == j) {
        cout << "A" << i;
        return;
    }

    int n = s[i][j];
    cout << "(";
    print_order(s, i, n);
    print_order(s, n + 1, j);
    cout << ")";
}

int main() {
    int n;
    cout << "Enter number of matrices: ";
    cin >> n;

    pair<int, int> A[n + 1];
    float a, b;
    int p[n + 2];
    for (int i = 1; i < n + 1; i++) {
        cout << "Enter order of A" << i << " matrix: ";
        cin >> a >> b;
        A[i].first = a;
        A[i].second = b;
        if (A[i].first != a || A[i].second != b) {
            do {
                cout << "Enter integer value only: ";
                cin >> a >> b;
                A[i].first = a;
                A[i].second = b;
            } while (A[i].first != a || A[i].second != b);
        }

        if (A[i].first < 1 || A[i].second < 1) {
            do {
                cout << "Enter positive dimensions only: ";
                cin >> A[i].first >> A[i].second;
            } while (A[i].first < 1 || A[i].second < 1);
        }
        if (i != 1 && A[i].first != A[i - 1].second) {
            cerr << "Incorrect input" << endl;
            return -1;
        }
        p[i] = A[i].second;
    }
    p[0] = A[1].first;

    int* m[n + 1];
    for (int i = 1; i < n + 1; i++) {
        m[i] = new int[n + 1];
        m[i][i] = 0;
    }
    int* s[n + 1];
    for (int i = 1; i < n + 1; i++) s[i] = new int[n + 1];
    matrix_chain_order(p, 1, n, m, s);
    cout << "Minimum cost: " << m[1][n] << endl;

    print_order(s, 1, n);
    cout << endl;
}