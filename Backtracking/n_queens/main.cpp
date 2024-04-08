#include<iostream>
#include<vector>

using namespace std;

int attempts = 0;
int solutions = 0;

bool is_legal(const vector<int> &v) {
    ++attempts;
    int value = v.back();
    // Test Horizontal
    for (int i = 0; i < v.size()-1; i++) {
        if (value == v[i]) return false;
    }

    // Test diagonal
    int offset = 1;
    for (int i = v.size()-2; i >= 0; i--) {
        if (value == v[i] + offset) return false;
        if(value == v[i] - offset) return false;
        ++offset;
    }
    return true;
}

void NQueens(int totalTOPlace, int leftToPlace, vector<int> &v) {
    if (leftToPlace == 0) {
        for(int i=0; i<totalTOPlace; i++) cout << v[i] << ' ';
        cout << endl;
        ++solutions;
        return;
    }
    // Avoid so many pushes and pops by taking it out of the loop.
    v.push_back(0);
    for(int i=0; i<totalTOPlace; i++) {
        v.back()= i;
        // Only move on when new queen doesn't collide with others.
        if(is_legal(v)) {
            NQueens(totalTOPlace, leftToPlace - 1, v);
        }
    }
    v.pop_back();
}

void NQueens(int n) {
    vector<int> v;
    v.reserve(n);
    NQueens(n, n, v);
}

int main() {
    int n;
    float m;
    cout << "Enter number of queens: ";
    cin >> m ;
    n = m;
    while(n!=m) {
    	cout << "Enter integer value: ";
    	cin >> m;
    	n = m;
	}
	if(n<=0) {
		cout << "Solution does not exist" << endl;
	}
    cout << "Row numbers for each columns: " << endl;
    NQueens(n);
    cout << "\nPossible number of solutions: " << solutions << endl;
    cout << "Number of attempts: " << attempts << endl;
}



/*
^ generally recurrsive functions are of type void
^ use vector when convinient compared to array
& possibly this problem could be done with array (take care of indices)
*/
