#include<iostream>
using namespace std;
int main(){

return 0;
}

#include <vector>
using namespace std;

// 1.
bool recursiveSol(int sum, vector<int>& arr, int i) {
    // Base case
    if (sum == 0) {
        return true;
    }
    if (i >= arr.size() || sum < 0) {
        return false;
    }

    // Explore both including and not including the current element
    return recursiveSol(sum - arr[i], arr, i + 1) || recursiveSol(sum, arr, i + 1);
}

bool isSubsetPresent(int n, int k, vector<int> &a) {
    // Check if a subset with sum k is possible starting from any index
    for (int i = 0; i < n; i++) {
        if (recursiveSol(k, a, i)) {
            return true;
        }
    }
    return false;
}



// 2.
bool recursiveSol(int sum, vector<int>& arr, int start, int current_sum) {
    // Base case
    if (current_sum == sum) {
        return true;
    }
    if (start >= arr.size() || current_sum > sum) {
        return false;
    }

    // Include the current element and move to the next
    if (recursiveSol(sum, arr, start + 1, current_sum + arr[start])) {
        return true;
    }

    // Exclude the current element and move to the next
    return recursiveSol(sum, arr, start + 1, current_sum);
}

bool isSubsetPresent(int n, int k, vector<int> &a) {
    return recursiveSol(k, a, 0, 0);
}
