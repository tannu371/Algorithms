#include<bits/stdc++.h>
using namespace std;

int minimumPushes(string word) {
    // ! There only 26 distinct elements and ascii value of characters are know. Therefore use array and not map.
    // & If map is used u need additional vector to sort it by its value.
    int arr[26]{};
    for(int i=0; i<word.length(); i++) {
        // ! ascii value of 'a' is 97 and 'A' is 65.
        arr[word[i]-97]++;
    }

    // ! This is how to write sort function using lamda.
    sort(arr, arr+26, [](int a, int b) {return a>b;});

    int n_clicks=0;
    int i=0;
    int clicks = 1;
    while(i<26 && arr[i]!=0) {
        // ! Access element before incrementing i as it can go out of bound at last index (26). Therefore it is safe to use for loop.
        n_clicks += (clicks*arr[i]);
        i++;
        if(i%8==0) clicks++;
    }

    return n_clicks;
}

int main() {

}