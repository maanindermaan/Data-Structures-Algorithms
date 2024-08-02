// Implement a simple meeting assistant. A list of strings, events[n], in the form "person_name> <action> <start> <end>" is provided
// where person_name performs action from start to end, both inclusive. Times are formatted HH:MM.
// Find the earliest time in the day, from "00:00" to
// "23:59", when all people mentioned in at least one event are available for a meeting of k minutes.
// Report the answer as "HH:MM" or the string "-1" if it is not possible.
// Example:
// events = [ "Alex sleep 00:00 08:00", "Sam sleep
// 07:00 13:00", "Alex lunch 12:30 13:59"]
// k = 60
// Alex is not available until 8:00. After that, Sam is not available until 13:00. Then Alex is busy until
// 13:59. Return the earliest time they are both available, "14:00"
// Function Description
// Complete the function getEarliestMeetTime in the editor below.
// getEarliestMeetTime takes the following arguments:
// string events[n]: event descriptors int k: meeting duration
// Returns
// string: the earliest time for the meeting or "-1"
// If it is not possible

// Constraints
// ﻿﻿ 1 ≤ n ≤ 10^5
// ﻿﻿ 1 ≤ length of events[i] ≤ 40
// ﻿﻿ 1 ≤ k ≤ 1440
// ﻿﻿ It is guaranteed that the number of people is less than 5000.
// ﻿﻿ It is guaranteed that no person's events overlap.



// Solution : 
#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>

using namespace std;

string getEarliestMeetTime(vector<string> events, int k) {
    map<string, vector<pair<int, int>>> schedule;

    for (const string& event : events) {
        istringstream iss(event);
        string name, action, start, end;
        iss >> name >> action >> start >> end;

        int start_minutes = stoi(start.substr(0, 2)) * 60 + stoi(start.substr(3, 2));
        int end_minutes = stoi(end.substr(0, 2)) * 60 + stoi(end.substr(3, 2));

        schedule[name].emplace_back(start_minutes, end_minutes);
    }

    vector<int> busy_times(1440, 0);

    for (const auto& person_schedule : schedule) {
        for (const auto& event : person_schedule.second) {
            for (int i = event.first; i <= event.second; ++i) {
                ++busy_times[i];
            }
        }
    }

    for (int i = 0; i <= 1440 - k; ++i) {
        bool available = true;
        for (int j = i; j < i + k; ++j) {
            if (busy_times[j] > 0) {
                available = false;
                break;
            }
        }
        if (available) {
            int hours = i / 60;
            int minutes = i % 60;
            return (hours < 10 ? "0" : "") + to_string(hours) + ":" +
                   (minutes < 10 ? "0" : "") + to_string(minutes);
        }
    }

    return "-1";
}

int main() {
    vector<string> events = {"Alex sleep 00:00 08:00", "Sam sleep 07:00 13:00", "Alex lunch 12:30 13:59"};
    int k = 60;

    string earliestTime = getEarliestMeetTime(events, k);
    cout << "Earliest time for the meeting: " << earliestTime << endl;

    return 0;
}
