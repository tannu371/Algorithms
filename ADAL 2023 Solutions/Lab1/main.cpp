#include<iostream>
#include<string>
#include<fstream>
#include<sstream>

using namespace std;

// increasing order

struct node {
    string admission_id;
    string name;
    node* horizontal;
    node* vertical;
};

node* initstudent() {
    node* head=NULL;
    head->horizontal = NULL;
    head->vertical = NULL;

    node** mesh = new node*[160];
    for (int i = 0; i < 160; ++i) {
        mesh[i] = new node;
        mesh[i] = NULL;
        if(i%7 == 6) mesh[i]->horizontal = NULL;
        else mesh[i]->horizontal = mesh[i+1];
        if(i>(160-16)) mesh[i]->vertical = NULL;
        else mesh[i]->vertical = mesh[i+16];
    }

    head->horizontal = mesh[0];

    return head;
}

int partition(string admission_no[], string name[], int low, int high) {
    int pIndex = low;
    int i=low, j=high;
    while(i<j) {
        while(name[i] <= name[pIndex] && i<high) i++;
        while(name[j] > name[pIndex]) j--;
        if(i<j) {
            string temp = name[i];
            name[i] = name[j];
            name[j] = temp;

            temp = admission_no[i];
            admission_no[i] = admission_no[j];
            admission_no[j] = temp;

            j--;
        }
    }

    string temp = admission_no[pIndex];
    admission_no[pIndex] = admission_no[j];
    admission_no[j] = temp;
    pIndex = j;

    return pIndex;
}

void sort_by_name(string admission_no[], string name[], int low, int high) {
    if(low>=high) return;
    int pIndex = partition(name, admission_no, low, high);
    sort_by_name(name, admission_no , low, pIndex-1);
    sort_by_name(name, admission_no , pIndex+1, high);
}

void storestudent(node* head) {
    ifstream in_file {"student.txt"};

    if(!in_file) {
        cout << "File open error" << endl;
    }

    string line;
    string admission_no[160];
    string name[160];

    int i=0;
    while(getline(cin, line)) {
        std::istringstream iss{line};
        iss >> admission_no[i] >> name[i];
        i++;
    }

    sort_by_name(admission_no, name, 0, 160);

    node* temp = head->horizontal;
    node* tempv = head->horizontal;

    for(int i=0; i<10; i++) {
        for(int j=0; j<16; j++) {
            int m=16;
            if(i%2==0){
                temp->admission_id = admission_no[16*i+j];
                temp->name = name[16*i+j];
            } else {
                temp->admission_id = admission_no[16*i+j+m-1];
                temp->name = name[16*i+j+m-1];
                m-=2;
            }
            temp = temp->horizontal;
        }
        temp = tempv->vertical;
        tempv = tempv->vertical;
    }
    
}

void traversecount(node* A) {
    string admission_no;
    cout << "Enter admission no. of student to find: ";
    cin >> admission_no;
    node* temp;
    node* tempv = A->horizontal;
    for(int i=0; i<160; i++) {
        if(i%16==0) {
            temp = tempv;
            tempv = tempv->vertical;
        }
        if(temp->admission_id == admission_no) {
            cout << "Admission Number: " << temp->admission_id << endl;
            cout << "Name: " << temp->name << endl;
            cout << "Total hops traversed: " << i+1 << endl;
            break;
        }
        temp = temp->horizontal;
    }
}

int main() {
    node* A = initstudent();
    storestudent(A);
    traversecount(A);
}