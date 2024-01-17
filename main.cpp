/*
Name: Dev Radadia
ID No: 21JE0298
*/

#include <iostream>
#include <iomanip>
using namespace std;

int arbi[100][100];

void MagicSquare(int n) {
    int magic[n][n];
    memset(magic, 0, sizeof(magic));

    int i = n/2, j = n-1, num = 1, cost = 0, flag = 1;

    while(num <= n*n) {
    	if((i == -1) and (j == n)) {
			i = 0;
            j = n-2;
        }
        else {
            if(i < 0) i = n-1;
            if(j == n) j = 0;
        }

        if(magic[i][j]) {
			i++;
            j -= 2;
			continue;
        }
        else {
        	magic[i][j] = num++;
        	cost += abs(arbi[i][j] - magic[i][j]);
		}
 		
		i--;
        j++;
    }

    
	int temp_cost = 0;
	for(int i=0; i<n; i++) {
		for(int j=n-1; j>=0; j--) temp_cost += abs(arbi[i][j] - magic[i][j]);
	}
	if(temp_cost < cost) {
		cost = temp_cost;
		flag = 2;
	}
	

	temp_cost = 0;
	for(int j=n-1; j>=0; j--) {
		for(int i=0; i<n; i++) temp_cost += abs(arbi[i][j] - magic[i][j]);
	}
	if(temp_cost < cost) {
		cost = temp_cost;
		flag = 3;
	}
	
	temp_cost = 0;
	for(int j=n-1; j>=0; j--) {
		for(int i=n-1; i>=0; i--) temp_cost += abs(arbi[i][j] - magic[i][j]);
	}
	if(temp_cost < cost) {
		cost = temp_cost;
		flag = 4;
	}
	
	
	temp_cost = 0;
	for(int i=n-1; i>=0; i--) {
		for(int j=n-1; j>=0; j--) temp_cost += abs(arbi[i][j] - magic[i][j]);
	}
	if(temp_cost < cost) {
		cost = temp_cost;
		flag = 5;
	}
	
	temp_cost = 0;
	for(int i=n-1; i>=0; i--) {
		for(int j=0; j<n; j++) temp_cost += abs(arbi[i][j] - magic[i][j]);
	}
	if(temp_cost < cost) {
		cost = temp_cost;
		flag = 6;
	}
	
	
	temp_cost = 0;
	for(int j=0; j<n; j++) {
		for(int i=n-1; i>=0; i--) temp_cost += abs(arbi[i][j] - magic[i][j]);
	}
	if(temp_cost < cost) {
		cost = temp_cost;
		flag = 7;
	}
	
	temp_cost = 0;
	for(int j=0; j<n; j++) {
		for(int i=0; i<n; i++) temp_cost += abs(arbi[i][j] - magic[i][j]);
	}
	if(temp_cost < cost) {
		cost = temp_cost;
		flag = 8;
	}
	
	cout<<"\nThe minimum cost: "<<cost<<endl;
	
	
	cout<<"The minimum cost magic square:\n";
	if(flag == 1) {
		for(int i=0; i<n; i++) {
	        for (int j=0; j<n; j++) cout<<setw(4)<<magic[i][j]<< " ";
	        cout << endl;
	    }
	}
	else if(flag == 2) {
		for(int i=0; i<n; i++) {
	        for (int j=n-1; j>=0; j--) cout<<setw(4)<<magic[i][j]<< " ";
	        cout << endl;
	    }
	}
	else if(flag == 3) {
		for(int j=n-1; j>=0; j--) {
	        for (int i=0; i<n; i++) cout<<setw(4)<<magic[i][j]<< " ";
	        cout << endl;
	    }
	}
	else if(flag == 4) {
		for(int j=n-1; j>=0; j--) {
	        for (int i=n-1; i>=0; i--) cout<<setw(4)<<magic[i][j]<< " ";
	        cout << endl;
	    }
	}
	else if(flag == 5) {
		for(int i=n-1; i>=0; i--) {
	        for (int j=n-1; j>=0; j--) cout<<setw(4)<<magic[i][j]<< " ";
	        cout << endl;
	    }
	}
	else if(flag == 6) {
		for(int i=n-1; i>=0; i--) {
	        for (int j=0; j<n; j++) cout<<setw(4)<<magic[i][j]<< " ";
	        cout << endl;
	    }
	}
	else if(flag == 7) {
		for(int j=0; j<n; j++) {
	        for (int i=n-1; i>=0; i--) cout<<setw(4)<<magic[i][j]<< " ";
	        cout << endl;
	    }
	}
	else {
		for(int j=0; j<n; j++) {
	        for (int i=0; i<n; i++) cout<<setw(4)<<magic[i][j]<< " ";
	        cout << endl;
	    }
	}
}

int main() {
	cout<<"Enter the order of matrix: ";
	int n;
	cin>>n;
	
	cout<<"\nEnter an arbitrary matrix:\n";
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) cin>>arbi[i][j];
	}
	
	MagicSquare(n);
}
