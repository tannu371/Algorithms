#include<iostream>
using namespace std;

struct Object {
    int id;
    float weight;
    float profit;
};

/* To calculate the maximum obtainable value at item i and knapsack weight j,
    i) Calculate maximum value without item i which is at row i-1 column j.
    ii) To Calculate maximum value with item i, we first need to compare the weight of item i with the knapsack’s weight capacity j. 
    If item i weighs more , we can’t include it and maximum obtainable value is at row i-1 column j. 
    Otherwise maximum value = the value of item i + the maximum value that can be obtained with the remaining capacity of the knapsack (knapsack'weight capacity j - weight of i).
    Maximum obtainable value  is max(maximum value without i, maximum value with i)
    The final solution is at the last row in the last column, which represents the maximum value obtainable with all the items and the full capacity of the knapsack.
*/
int Knapsack0_1(int n, Object* objs, int w) {
    int** dp = new int*[n+1];
    for(int i=0; i<=n; i++) {
        dp[i] = new int[w+1];
    } 

    dp[0][0] = 0;
    for(int i=1; i<=n; i++) {
        dp[i][0] = 0;
    }
    for(int j=1; j<=w; j++) {
        dp[0][j] = 0;
    }

    int max;
    int max_i;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=w; j++) {
            max = dp[i-1][j];
            if(objs[i-1].weight > j) max_i = max;
            else max_i = objs[i-1].profit + dp[i-1][j-int(objs[i-1].weight)];
            if(max_i > max) dp[i][j] = max_i;
            else dp[i][j] = max;
        }
    }

   return dp[n][w]; 
}

int main() {
    int n;
    do {
        cout << "Enter number of items: ";
        cin >> n;
    } while (n <= 0);

    Object* objs = new Object[n];
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

    do {
        cout << "Enter maximum positive integer weight that can be carried in bag: ";
        cin >> w;
    } while(w<=0);
    
    cout << "Maximum obtainable value: " << Knapsack0_1(n, objs, w);
}

/*
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> iv(n);
    for(int i=0; i<n; i++) cin >> iv[i];
    vector<int> articles(n);
    for(int i=0; i<n; i++) cin >> articles[i];
    int p;
    cin >> p;

    vector<int> vec(p+1,0);
    vector<vector<int>> dp(n+1, vec);

    int max_i;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=p; j++) {
            dp[i][j] = dp[i-1][j];
            if(articles[i-1] <= j) max_i = iv[i-1] + dp[i-1][j-articles[i-1]];
            else max_i = dp[i][j];
            if(max_i > dp[i][j]) dp[i][j] = max_i;
        }
    }

    cout << dp[n][p];

    return 0;
}
*/