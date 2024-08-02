#include<iostream>
#include<vector>
using namespace std;
int main(){

return 0;
}

#include <limits.h>
int upperBound(vector<int> &arr, int x, int n){
	int start = 0;
	int end = n-1;
	int ans = n;

	while(start <= end){
		int mid = start + (end-start)/2;
		if(arr[mid] > x){
			ans = mid;
			// search in left
			end = mid-1;
		}
		else{
			// search in right
			start = mid+1;
		}
	}
	return ans;
}

int blackBox(vector<vector<int>> &arr, int n, int m , int mid){
    int total_greater_equals = 0;
    for(int i=0 ; i<n ; i++){
        // going to every row and calculating the value and summing value from every row
        total_greater_equals += upperBound(arr[i], mid, m);
    }
    return total_greater_equals;
}

int median(vector<vector<int>> &arr, int n, int m) {
    // n -> rows 
    // m -> cols
    // minimum element in 0th column
    int start = INT_MAX;
    for(int row=0 ; row < n ; row++){
        start = min(start , arr[row][0]);
    }
    // maximum element in last column 
    int end = INT_MIN;
    for(int row=0 ; row < n ; row++){
        end = max(end , arr[row][m-1]);
    }
    int required = (m*n) / 2;
    // applying B.S. here
    while(start <= end){
        int mid = start + (end-start)/2;

        int greaterEquals = blackBox(arr , n , m , mid);
        
        if(greaterEquals <= required){
            // becuase mujhe just bada chahiye that's why <= 
            // move aage for bada element
            start = mid+1;
        }
        else{
            // oops go back zyada aage aagye
            end = mid-1;
        }
    }
    return start;
}