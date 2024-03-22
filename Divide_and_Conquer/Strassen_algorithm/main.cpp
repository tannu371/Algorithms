// Matrix Multiplication
#include<iostream>
using namespace std;

/*
* Normally 8x and 4+ in (n/2 x n/2) matrix multiplication 
! T(n) = 8T(n/2) + O(n²)
& Time Complexity: O(n³)
*/


/*
* Volker Strassen
* 7x and 18+ 
! T(n) = 7T(n/2) + O(n²)
& Time Complexity: O(n^2.81)
~ recursive method
~ It is complex than conventional algorithm to implement
*/

int** addMat(int** A, int** B, int n) {
    int** result = new int*[n];
    for(int i=0; i<n; i++) {
        result[i] = new int[n];
        for(int j=0; j<n; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
    return result;
}

int** subMat(int** A, int** B, int n) {
    int** result = new int* [n];
    for (int i = 0; i < n; i++) {
        result[i] = new int[n];
        for (int j = 0; j < n; j++) {
            result[i][j] = A[i][j] - B[i][j];
        }
    }
    return result;
}

int** Strassen_multiplication(int** A, int** B, int n) {
    int** C;
    C = new int*[n];
    if(n == 1) {
        C[0] = new int[1];
        C[0][0] = A[0][0] * B[0][0];
        return C;
    }

    int** A11 = new int*[n/2];
    int** A12 = new int*[n/2];
    int** A21 = new int*[n/2];
    int** A22 = new int*[n/2];

    int** B11 = new int*[n / 2];
    int** B12 = new int*[n / 2];
    int** B21 = new int*[n / 2];
    int** B22 = new int*[n / 2];

    for(int i=0; i<n/2; i++) {
        A11[i] = new int[n / 2];
        A12[i] = new int[n / 2];
        A21[i] = new int[n / 2];
        A22[i] = new int[n / 2];

        B11[i] = new int[n / 2];
        B12[i] = new int[n / 2];
        B21[i] = new int[n / 2];
        B22[i] = new int[n / 2];

        for(int j=0; j<n/2; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j+n/2];
            A21[i][j] = A[i+n/2][j];
            A22[i][j] = A[i+n/2][j+n/2];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + n / 2];
            B21[i][j] = B[i + n / 2][j];
            B22[i][j] = B[i + n / 2][j + n / 2];
        }
    }

    int** P = Strassen_multiplication(addMat(A11, A22, n/2), addMat(B11, B22, n/2), n/2);
    int** Q = Strassen_multiplication(B11, addMat(A21, A22, n/2), n/2);
    int** R = Strassen_multiplication(A11, subMat(B12, B22, n/2), n/2);
    int** S = Strassen_multiplication(A22, subMat(B21, B11, n/2), n/2);
    int** T = Strassen_multiplication(B22, addMat(A11, A12, n/2), n/2);
    int** U = Strassen_multiplication(subMat(A21, A11, n/2), addMat(B11, B12, n/2), n/2);
    int** V = Strassen_multiplication(subMat(A12, A22, n/2), addMat(B21, B22, n/2), n/2);

    int** C11 = addMat(subMat(addMat(P, S, n/2), T, n/2), V, n/2);
    int** C12 = addMat(R, T, n/2);
    int** C21 = addMat(Q, S, n/2);
    int** C22 = addMat(subMat(addMat(P, R, n / 2), Q, n / 2), U, n / 2);

    for(int i=0; i<n/2; i++) {
        C[i] = new int[n/2];
        for(int j=0; j<n/2; j++) {
            C[i][j] = C11[i][j];
            C[i][j+n/2] = C12[i][j];
            C[i+n/2][j] = C21[i][j];
            C[i+n/2][j+n/2] = C22[i][j];
        }
    }

    return C;
}



int main() {
    int n;
    cout << "Enter order of matrix: ";
    cin >> n;
    int** A;
    int** B;
    A = new int*[n];
    B = new int*[n];
    cout << "Enter 1st matrix: " << endl;
    for(int i=0; i<n; i++) {
        A[i] = new int[n];
        for(int j=0; j<n; j++) {
            cin >> A[i][j];
        }
    }

    cout << "Enter 2nd matrix of same order: " << endl;
    for (int i = 0; i < n; i++) {
        B[i] = new int[n];
        for (int j = 0; j < n; j++) {
            cin >> B[i][j];
        }
    }

    int** result = Strassen_multiplication(A, B, n);
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}