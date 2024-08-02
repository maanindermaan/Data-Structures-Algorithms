// In simpler terms, you are counting the number of distinct, non-overlapping windows of size 'k' where the 
// temperatures are increasing. Each of these windows represents a time period where temperatures started 
// increasing again after a period of stagnation

#include <iostream>
#include <vector>
using namespace std;

bool checkIncreasing(int start, int end, vector<int>& arr) {
    bool flag = true;
    for (int i = start; i < end; i++) {
        if (arr[i] >= arr[i + 1]) {
            return false;
        }
    }
    return flag;
}

int getMinDays(vector<int>& arr, int k) {
    int i = 0;
    int j = k - 1;
    int count = 0;
    while (j < arr.size()) {
        if (checkIncreasing(i, j, arr) == true) {
            cout<<arr[i]<<" "<<arr[j]<<endl;
            count++;
        }
        i++;
        j++;
    }

    return count;
}

int main() {
    vector<int> arr {3, 5, 2, 6, 1, 10, 12, 7, 8, 13, 19, 20};
    int k = 3;

    cout << getMinDays(arr, k);
    return 0;
}
