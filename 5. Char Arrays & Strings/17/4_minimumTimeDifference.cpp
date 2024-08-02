#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;

int minimumTimeDifference(vector<string>& timePoints){
    // Step 1 -> Convert time string into mintues integer value
    vector<int>minutes;

    for(int i=0 ; i<timePoints.size() ; i++){
        string curr = timePoints[i];

        int hours = stoi(curr.substr(0,2));
        int minute = stoi(curr.substr(3,2));
        int totalMinutes = hours*60 + minute;
        minutes.push_back(totalMinutes);
    }

    // Step 2 -> Sort
    sort(minutes.begin() , minutes.end());

    // Step 3 -> difference and calculate minimum difference
    int mini = INT_MAX;
    int n = minutes.size(); // because we want when i+1 is iterated it gets out of loop because when i will be last index i+1 will give error

    for(int i=0 ; i<n-1 ; i++){
        int diff = minutes[i+1] - minutes[i];
        mini = min(mini , diff); 
    }

    // Step 4 : Last difference with first element - Something missing game !
    int lastDiff1 = (minutes[0] + 1440) - minutes[n-1];
    int lastDiff2 = (minutes[n-1]) - minutes[0];
    int lastDiff = min(lastDiff1 , lastDiff2);
    
    mini = min(mini , lastDiff);
    return mini;

}

int main(){
    vector<string>timePoints{{"23:59"},{"00:00"}};
    int ans = minimumTimeDifference(timePoints);
    cout<<ans;
return 0;
}




// My approach
class Solution {
public:
    int convertIntoMinutes(string s) {
        int hours = stoi(s.substr(0, 2)); 
        int minutes = stoi(s.substr(3,2));  
        return hours * 60 + minutes;      
    }

    int findMinDifference(vector<string>& timePoints) {
        vector<int>minutes;
        for (auto time : timePoints) {
            minutes.push_back(convertIntoMinutes(time));
        }
        sort(minutes.begin(), minutes.end()); // Sort the minutes vector
        int minDiff = INT_MAX;
        for (int i = 1; i < minutes.size(); ++i) {
            minDiff = min(minDiff, minutes[i] - minutes[i - 1]);
        }
        // to check the cyclic nature
        minDiff = min(minDiff , minutes.front()+(24*60 - minutes.back()));
        return minDiff;
    }
};