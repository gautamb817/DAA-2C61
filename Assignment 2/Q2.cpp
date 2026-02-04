#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int toMinutes(string time) {
    int hours = stoi(time.substr(0, 2));
    int minutes = stoi(time.substr(3, 2));
    return hours * 60 + minutes;
}

int main() {
    int n = 5;

    vector<string> arrivalTime = {"09:00", "09:10", "09:20", "11:00", "11:20"};
    vector<string> departureTime = {"09:40", "12:00", "09:50", "11:30", "11:40"};

    vector<int> arrival(n), departure(n);

    
    for (int i = 0; i < n; i++) {
        arrival[i] = toMinutes(arrivalTime[i]);
        departure[i] = toMinutes(departureTime[i]);
    }

    
    sort(arrival.begin(), arrival.end());
    sort(departure.begin(), departure.end());

    int platformsNeeded = 0, maxPlatforms = 0;
    int i = 0, j = 0;

    
    while (i < n && j < n) {
        if (arrival[i] <= departure[j]) {
            platformsNeeded++;
            maxPlatforms = max(maxPlatforms, platformsNeeded);
            i++;
        } else {
            platformsNeeded--;
            j++;
        }
    }

    cout << "Minimum number of platforms required = "
         << maxPlatforms << endl;

    return 0;
}
