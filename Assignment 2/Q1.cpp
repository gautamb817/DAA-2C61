#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N = 6;

    vector<int> start  = {1, 3, 0, 5, 8, 5};
    vector<int> finish = {2, 4, 6, 7, 9, 9};

    
    vector<pair<int, int>> activities;
    for (int i = 0; i < N; i++) {
        activities.push_back({start[i], finish[i]});
    }

    
    sort(activities.begin(), activities.end(),
         [](pair<int, int> a, pair<int, int> b) {
             return a.second < b.second;
         });

    cout << "Selected activities:\n";

    
    int count = 1;
    int lastFinish = activities[0].second;

    cout << "(" << activities[0].first << ", " << activities[0].second << ")";

    
    for (int i = 1; i < N; i++) {
        if (activities[i].first >= lastFinish) {
            cout << ", (" << activities[i].first
                 << ", " << activities[i].second << ")";
            count++;
            lastFinish = activities[i].second;
        }
    }

    cout << "\nMaximum number of activities = " << count << endl;

    return 0;
}
