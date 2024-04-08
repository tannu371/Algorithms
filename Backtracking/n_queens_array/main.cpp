#include<iostream>

using namespace std;

int attempts = 0;
int solutions = 0;

bool is_legal(int* v, int totalPlaced) {
    ++attempts;
    int value = v[totalPlaced];
    // Horizontal
    for (int i = 0; i < totalPlaced; i++) {
        if (value == v[i]) return false;
    }

    // diagonal
    int offset = 1;
    for (int i = totalPlaced - 1; i >= 0; i--) {
        if (value == v[i] + offset) return false;
        if (value == v[i] - offset) return false;
        ++offset;
    }
    return true;
}

void NQueens(int totalTOPlace, int* v = NULL, int totalPlaced = 0) {
    if (v == NULL) {
        v = new int[totalTOPlace];
    }
    if (totalPlaced == totalTOPlace) {
        for (int i = 0; i < totalTOPlace; i++) cout << v[i] << ' ';
        cout << endl;
        ++solutions;
        return;
    }
    // Avoid so many pushes and pops by taking it out of the loop.
    for (int i = 0; i < totalTOPlace; i++) {
        v[totalPlaced] = i;
        // Only move on when new queen doesn't collide with others.
        if (is_legal(v, totalPlaced)) {
            NQueens(totalTOPlace, v, totalPlaced + 1);
        }
    }
}

int main() {
    int n;
    cout << "Enter number of queens: ";
    cin >> n;
    NQueens(n);
    cout << "Possible number of solutions: " << solutions << endl;
    cout << "Number of attempts: " << attempts << endl;
}



/*
^ generally recurrsive functions are of typr void
^ before taking value at a particular index of array check if it is in range
*/