#include <iostream>
#include <vector>

using namespace std;

vector<int> searchRange(vector<int>& arr, int target) {
    vector<int> ans;
    // applying binary Search Logic
    int start = 0;
    int end = arr.size() - 1;
    int firstElement = -1;
    int lastElement = -1;

    // for 1st position
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] == target) {
            firstElement = mid;
            // search in left
            end = mid - 1;
        } else if (arr[mid] > target) {
            // move left
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    
    ans.push_back(firstElement);
    
    start = 0;  // Resetting start for the second binary search
    end = arr.size() - 1; 

    // for last position
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] == target) {
            lastElement = mid;
            // search in right
            start = mid + 1;
        } else if (arr[mid] > target) {
            // move left
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    ans.push_back(lastElement);
    return ans;
}

int main() {
    // Example vector
    vector<int> exampleVector = {1, 2, 3};
    
    // Example target value
    int targetValue = 1;

    // Calling the searchRange function
    vector<int> result = searchRange(exampleVector, targetValue);

    // Displaying the result
    cout << "Result: [" << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}



class Solution {
public:
    vector<int> searchRange(vector<int>& arr, int target) {
        vector<int>ans;
        // applying binary Search Logic
        int start = 0;
        int end = arr.size()-1;
        int firstElement = -1;
        int lastElement = -1;

        // for 1st position
        while(start <= end){
            int mid = start + (end - start)/2;
            if(arr[mid] == target){
                firstElement = mid;
                // search in left 
                end = mid-1;
            }
            else if(arr[mid] > target){
                // move left
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        start = 0;
        end = arr.size()-1;

        // for last position
        while(start <= end){
            int mid = start + (end - start)/2;
            if(arr[mid] == target){
                lastElement = mid;
                // search in right 
                start = mid+1;
            }
            else if(arr[mid] > target){
                // move left
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }

        ans.push_back(firstElement);
        ans.push_back(lastElement);
        return ans;
    }
};


