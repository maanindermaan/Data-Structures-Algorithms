// Approach 1
#include<iostream>
#include<vector>
using namespace std;
int main(){


return 0;
}

int binarySearch(vector<int>& arr, int target) {
    int start = 0;
    int end = arr.size() - 1;
    int mid = (start + end) / 2;

    while (start <= end) {
        if (target == arr[mid]) {
            // Element found
            return mid;
        } else if (target < arr[mid]) {
            // Search in left
            end = mid - 1;
        } else {
            // Search in right
            start = mid + 1;
        }

        // Calculate mid again because mid will be updated due to above two elseif and else loops
        mid = (start + end) / 2;
    }

    // Element not found
    return -1;
}

pair<int, int> search(vector<vector<int>>& matrix, int x) {
    pair<int, int> ans;
    int index;
    for (int i = 0; i < matrix.size(); i++) {
        index = binarySearch(matrix[i], x);
        if (index != -1) {
            ans = {i, index};
            return ans;
        }
    }
    // Element not found
    return {-1, -1};
}





// 2. Best Approach
#include <bits/stdc++.h> 
pair<int, int> search(vector<vector<int>> matrix, int x)
{
    int row = 0;
    int col = matrix[0].size()-1;

    while(row < matrix.size() && col>=0){
        if(matrix[row][col] == x){
            return {row , col};
        }
        else if(matrix[row][col] < x){
            row++;
        }
        else{
            col--;
        }
    }
    return {-1 , -1};
}