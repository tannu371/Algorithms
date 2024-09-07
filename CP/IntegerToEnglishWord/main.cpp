#include<bits/stdc++.h>
using namespace std;

// ! Brute Force

string numberToWords(int num) {
    unordered_map<int, string> mp;
    mp[0] = "Zero";
    mp[1] = "One";
    mp[2] = "Two";
    mp[3] = "Three";
    mp[4] = "Four";
    mp[5] = "Five";
    mp[6] = "Six";
    mp[7] = "Seven";
    mp[8] = "Eight";
    mp[9] = "Nine";
    mp[10] = "Ten";
    mp[11] = "Eleven";
    mp[12] = "Twelve";
    mp[13] = "Thirteen";
    mp[14] = "Fourteen";
    mp[15] = "Fifteen";
    mp[16] = "Sixteen";
    mp[17] = "Seventeen";
    mp[18] = "Eighteen";
    mp[19] = "Nineteen";
    mp[20] = "Twenty";
    mp[30] = "Thirty";
    mp[40] = "Forty";
    mp[50] = "Fifty";
    mp[60] = "Sixty";
    mp[70] = "Seventy";
    mp[80] = "Eighty";
    mp[90] = "Ninety";
    mp[100] = "Hundred";
    mp[1000] = "Thousand";
    mp[1000000] = "Million";
    mp[1000000000] = "Billion";

    vector<string> word;
    int temp = num;
    
    int temp2 = temp/1000000000;
    if(temp2) {
        word.push_back(mp[temp2]);
        word.push_back(mp[1000000000]);
        temp = temp%1000000000;
    }

    temp2 = temp/100000000;
    int temp3 = temp2;
    if(temp2) {
        word.push_back(mp[temp2]);
        word.push_back(mp[100]);
        temp = temp%100000000;
    } 

    temp2 = temp/1000000;
    if(temp2) {
        if(temp2>=20) {
            word.push_back(mp[(temp2/10 *10)]);
            if(temp2%10>0) {
                word.push_back(mp[temp2%10]);
            }
        } else {
            word.push_back(mp[temp2]);
        }
        word.push_back(mp[1000000]);
        temp = temp%1000000;
    } else if(temp3) {
        word.push_back(mp[1000000]);
    } 

    temp2 = temp/100000;
    temp3 = temp2;
    if(temp2) {
        word.push_back(mp[temp2]);
        word.push_back(mp[100]);
        temp = temp%100000;
    }

    temp2 = temp/1000;
    if(temp2) {
        if(temp2>=20) {
            word.push_back(mp[(temp2/10 *10)]);
            if(temp2%10>0) {
                word.push_back(mp[temp2%10]);
            }
        } else {
            word.push_back(mp[temp2]);
        }
        word.push_back(mp[1000]);
        temp = temp%1000;
    } else if(temp3) {
        word.push_back(mp[1000]);
    }

    temp2 = temp/100;
    if(temp2) {
        word.push_back(mp[temp2]);
        word.push_back(mp[100]);
        temp = temp%100;
    }

    if(temp>=20) {
        word.push_back(mp[(temp/10 *10)]);
        if(temp%10>0) {
            word.push_back(mp[temp%10]);
        }
    } else if(temp) {
        word.push_back(mp[temp]);
    } 

    if(!num) word.push_back(mp[num]);

    string str= word[0];
    for(int i=1; i<word.size();i++) {
        str +=" ";
        str += word[i];
    } 

    return str;
}

int main() {

}