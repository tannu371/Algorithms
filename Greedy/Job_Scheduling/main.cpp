#include<iostream>
#include<algorithm>

using namespace std;

// Time complexity: O(nlog₂n)

struct Job {
    int id;
    int deadline;
    int profit;
};

bool compare(Job& j1, Job& j2) {
    if (j1.deadline == j2.deadline) return j1.profit > j2.profit;
    return j1.deadline > j2.deadline;
}

void Job_scheduling() {
    int n;
    do {
        cout << "Enter the number of jobs (n) : ";
        cin >> n;
    } while(n<=0);
    
    

    Job* jobs = new Job;
    int d, p;
    for (int i = 0; i < n; i++) {
        cout << "Enter Deadline and Profit for job " << i + 1 << ": ";
        cin >> d >> p;

        while (d <= 0) {
            cout << "This job should have been done earlier. Please enter positive deadline only." << endl;
            cout << "Press 1: To exclude job " << i+1 << endl;
            cout << "Press 2: To Re-enter values for job" << i+1 << endl;
            int input;
            cin >> input;
            switch(input) {
                case 1 : goto exit_loop;
                case 2: cout << "Re-enter deadline and profit for job " << i + 1 << " : ";
            }
            cin >> d >> p;
        }
        exit_loop: ;

        jobs[i].id = i + 1;
        jobs[i].deadline = d;
        jobs[i].profit = p;
    }

    sort(jobs, jobs + n, compare);

    int x[n];
    for (int i = 0; i < n; i++) x[i] = 0;
    int i = 0;
    d = jobs[i].deadline;
    while (i < n) {
        if(d <= 0) {
            break;
        }
        i++;
        if (jobs[i].deadline == d) {
            continue;
        }
        x[i] = 1;
        d = jobs[i].deadline;
    }

    int max_profit = 0;
    cout << "\nSelected Jobs" << endl;
    cout << "-----------------------------------" << endl;
    cout << "Id\tDeadline\tProfit" << endl;
    for (int i = 0; i < n; i++) {
        if (x[i] == 1) {
            cout << jobs[i].id << '\t' << jobs[i].deadline << '\t' << jobs[i].profit << endl;
        }
    }

    cout << "\nMaximum Profit : " << max_profit << endl;

}


int main() {
    Job_scheduling();
}

