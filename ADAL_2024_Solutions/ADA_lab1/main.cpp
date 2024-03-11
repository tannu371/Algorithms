// !! Still need to work on it.
/* 
! magic constant = n(n²+1)/2;
! matrix of 1 to n²
? next position : (i-1, j+1)
? if it already contains number : (i+2, j-1)
*/
#include<iostream>

using namespace std;

void decrement(int &a, int n) {
    if((a-1)==-1) a=n-1;
    else a--;
}

void increment(int &a, int n) {
    if((a+1)==n) a=0;
    else a++;
}

int** magic_square(int i, int n) {
    int** magic;
    magic = new int*[n];
    for(int i=0; i<n; i++) magic[i] = new int[n];

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) magic[i][j] = 0;
    }

    int p = i/n;
	int q = i%n;
	magic[p][q] = 1;
	for(int j=2; j<=n*n; j++) {
        decrement(p,n);
        increment(q,n);
		
        if(magic[p][q]) {
            increment(p,n);
            increment(p,n);
            decrement(q,n);
        }

		magic[p][q] = j;
	}
    return magic;
}

int calculate_cost(int** arbi, int** magic, int n) {
    int cost = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) cost += abs(arbi[i][j] - magic[i][j]);
    }
    return cost;
}

void print_magic_square(int** magic, int n) {
    cout << endl;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << magic[i][j] << "\t";
        }
        cout << endl;
    }
}

void min_cost_magic_square(int** arbi, int n) {
	int** magic;
	int cost[n*n];
	for(int i=0; i<n*n; i++) {
		magic = magic_square(i, n);
        cost[i] = calculate_cost(arbi, magic, n);
        print_magic_square(magic, n);
        cout  << "cost: " << cost[i] << endl;
       
	}
	
	int min = 0;
	for(int i=0; i<n*n; i++) {
		if(cost[min] >= cost[i]) min = i;
	}
	
	cout << "Minimum cost of creating magic square: " << cost[min] << endl;
	
	magic = magic_square(min, n);
    cout << "Minimum cost magic square: " << endl;
    print_magic_square(magic, n);
	
}

int main() {
	int n;
	cout << "Enter order of matrix: ";
	cin >> n;
	
	int **arbi;
	cout << "Enter arbitrary matrix: " << endl;
    arbi = new int*[n];
	for(int i=0; i<n; i++) arbi[i] = new int[n];

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) cin >> arbi[i][j];
    }

	min_cost_magic_square(arbi, n);
	
}

// 9 2 3 6 5 1 4 8 7