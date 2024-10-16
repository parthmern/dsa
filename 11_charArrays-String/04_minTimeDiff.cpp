#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

int findMinDifference(vector<string>& timePoints) {
    // Step 1: Convert time to minutes
    vector<int> minutes;

    for (int i = 0; i < timePoints.size(); i++) {
        string curr = timePoints[i];
        int hours = stoi(curr.substr(0, 2));
        int minute = stoi(curr.substr(3, 2));
        int totalMin = hours * 60 + minute;
        minutes.push_back(totalMin);
    }

    // Step 2: Sort the minutes
    sort(minutes.begin(), minutes.end());

    // Step 3: Find the minimum difference between consecutive time points
    int mini = INT_MAX;
    for (int i = 0; i < minutes.size() - 1; i++) {
        int diff = minutes[i + 1] - minutes[i];
        mini = min(mini, diff);
    }

    // Step 4: Check the difference between the first and last time points (circular difference)
    int lastDiff = (minutes[0] + 1440) - minutes[minutes.size() - 1];
    mini = min(mini, lastDiff);

    return mini;
}

int main() {
    // int n;
    // cout << "Enter the number of time points: ";
    // cin >> n;

    vector<string> timePoints {"00:00","23:59","00:00"};
    cout << "Enter the time points (in HH:MM format):" << endl;
    // for (int i = 0; i < n; i++) {
    //     cin >> timePoints[i];
    // }

    int result = findMinDifference(timePoints);
    cout << "The minimum time difference is: " << result << " minutes" << endl;

    return 0;
}
