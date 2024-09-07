#include<bits/stdc++.h>
using namespace std;

// Number of Senior Citizens - return number of passengers with age > 60, 11th and 12th char contains age.
/*
! ASCII Value (intVal = charVal -'0')
! Place Value (....., 100, 10, 1)
*/

int countSeniors(vector<string>& details) {
    int count=0;
    int age;
    for(int i=0; i<details.size();i++) {
        // subtract ascii value of 0 from char to get integer value. Multiple by power of 10 as required as per place value.
        age = (details[i][11]-'0')*10 + (details[i][12]-'0');
        cout << age << " ";
        count += (age>60);
    } 
    return count;   
}

/*
& stoi(str) : converts string to integer.
& str.substring(position, length)
! If you use these 2 function for solving this question, it takes more execution time. 
*/

int main() {

}
