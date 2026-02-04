#include <iostream>
#include <algorithm>

using namespace std;

struct Job {
    char id;
    int deadline;
    int profit;
};


bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

int main() {
    int N = 5;

    Job jobs[5] = {
        {'1', 2, 100},
        {'2', 1, 19},
        {'3', 2, 27},
        {'4', 1, 25},
        {'5', 3, 15}
    };

    
    sort(jobs, jobs + N, compare);

    
    int maxDeadline = 0;
    for (int i = 0; i < N; i++) {
        if (jobs[i].deadline > maxDeadline)
            maxDeadline = jobs[i].deadline;
    }

   
    char slot[10];
    for (int i = 1; i <= maxDeadline; i++) {
        slot[i] = '-';
    }

    int totalProfit = 0;
    int jobCount = 0;

    
    for (int i = 0; i < N; i++) {
        for (int t = jobs[i].deadline; t > 0; t--) {
            if (slot[t] == '-') {
                slot[t] = jobs[i].id;
                totalProfit += jobs[i].profit;
                jobCount++;
                break;
            }
        }
    }

    cout << "Selected Jobs: [";
    int first = 1;
    for (int i = 1; i <= maxDeadline; i++) {
        if (slot[i] != '-') {
            if (!first) cout << ", ";
            cout << "J" << slot[i];
            first = 0;
        }
    }
    cout << "]" << endl;

    cout << "Maximum Profit = " << totalProfit << endl;

    return 0;
}
