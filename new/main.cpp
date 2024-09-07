#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;


    int i=1;
    int j = n;
    while(true) {
        if(i>j) break;
        int mid = (i+j)/2;
        if(mid*mid == n) {
            cout << mid <<endl;
            break;
        }
        else if(mid*mid < n) {
            i = mid+1;
        } else {
            j = mid-1;
        }
    }


}