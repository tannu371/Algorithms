#include<iostream>

using namespace std;

void interchage(int a[], int i, int j) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

int partition(int s[], int f[], int low, int high) {
    int pIndex = low;
    int i=low, j=high;
    while(i<j) {
        while(f[i] <= f[pIndex] && i<high) i++;
        while(f[j] > f[pIndex]) j--;
        if(i<j) {
            interchage(f, i, j);
            interchage(s, i, j);

            j--;
        }
    }
    interchage(f, pIndex, j);
    interchage(s, pIndex, j);

    pIndex = j;
    return pIndex;
}

void Quick_Sort(int s[], int f[], int low, int high) {
    if(low>=high) return;
    int pIndex = partition(s, f, low, high);
    Quick_Sort(s, f, low, pIndex-1);
    Quick_Sort(s, f, pIndex+1, high);
}

// To select maximum-size set of mutually compatible activities (si >= fj) or (sj >= fi)
// Greedy: select in increasing order of finish time
// Time complexity: O(nlog₂n)
void Activity_selection() {
    int n;
    cout << "Enter number of activities: ";
    cin >> n;

    int s[n];
    cout << "Enter start time of each activity: ";
    for(int i=0; i<n; i++) cin >> s[i];

    int f[n];
    cout << "Enter finish time of each activity: ";
    for(int i=0; i<n; i++) cin >> f[i];

    // increasing order of finishing time
    Quick_Sort(s, f, 0, n-1);

    int index[n];
    for(int i=0; i<n; i++) index[i]=-1;

    index[0]=0;
    int j=1;

    int m=1;
    for(int i=1; i<n; i++) {
        if(s[i]>=f[j]) {
            index[m]=i;
            m++; 
            j=i;
        }
    }

    cout << "\nMaximum number of activities that can be selected: " << m << "\n"<< endl;
    cout << "\tstart time\t" << "finish time\t" << endl; 
    for(int i=0; i<m; i++) {
        cout << i+1 << ")\t" << s[index[i]] << "\t\t" << f[index[i]] << "\t\t" << endl;
    }
}

int Recursive_Activity_Selection(int s[], int f[], int i, int j, int num_act) {
    if(i==0) cout << num_act << ")\t" << s[i] << "\t\t" << f[i] << "\t\t" << endl;
    int m = i+1;
    while(m<=j && s[m] < f[i]) m = m+1;
    if(m<=j) {
        num_act++;
        cout << num_act << ")\t" << s[m] << "\t\t" << f[m] << "\t\t" << endl;
        return Recursive_Activity_Selection(s, f, m, j, num_act);
    }
    return num_act;  
}

int main() {

    // Iterative Method
    Activity_selection();

    // Recursive Method 

    int n;
    cout << "Enter number of activities: ";
    cin >> n;

    int s[n];
    cout << "Enter start time of each activity: ";
    for(int i=0; i<n; i++) cin >> s[i];

    int f[n];
    cout << "Enter finish time of each activity: ";
    for(int i=0; i<n; i++) cin >> f[i];

    Quick_Sort(s, f, 0, n-1);
    cout << "\n\tstart time\t" << "finish time\t" << endl;
    int num_act = 1;
    num_act = Recursive_Activity_Selection(s, f, 0, n-1, num_act);   
    cout << "\nMaximum number of activities that can be selected: " << num_act << "\n"<< endl;
    
}

// n = 11
// s = {1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12}
// 1 3 0 5 3 5 6 8 8 2 12
// f = {4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14}
// 4 5 6 7 8 9 10 11 12 13 14