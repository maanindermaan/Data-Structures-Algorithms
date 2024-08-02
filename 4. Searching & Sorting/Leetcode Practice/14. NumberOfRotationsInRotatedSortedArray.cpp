// Method -1
#include<iostream>
using namespace std;
int main(){

return 0;
}


// } Driver Code Ends
//User function template for C++
class Solution{
public:	

    int findPivot(int arr[] , int size){
        int start = 0;
        int end = size-1;
        while(start<=end){
            if(start==end){
                return start;
            }
            int mid = start + (end-start)/2;
            if(arr[mid]>arr[mid+1]){
                return mid;
            }
            else if(arr[mid]<arr[mid-1]){
                return mid-1;
            }
            else if(arr[start]>=arr[mid]){
                // Move Left
                end = mid-1;
            }
            else{
                // Move Right
                start = mid+1;
            }
        }
        return -1;
    }

	int findKRotation(int arr[], int n) {
	    int index = findPivot(arr , n);
	    index = index+1;
	    
	    if(index == n){
	        return 0;
	    }
	    else{
	        return index;
	    }
	}

};

// Method -2
class Solution{
public:	

	int findKRotation(int arr[], int n) {
	    int ans = INT_MAX;
        int start = 0;
        int end = n-1;
        int index = -1;
        while(start<=end){
            int mid=start+(end-start)/2;

            if(arr[start] <= arr[end]){
               if(arr[start] < ans){
                   index = start;
                   ans = arr[start];
               }
                break;
            }

            if(arr[mid]>=arr[start]){
                // left Subarray
                // store min and eliminate
                if(arr[start] < ans){
                    index = start;
                    ans = arr[start];
                }
                start = mid+1;
            }
            else{
                // Right Subaaray
                // store and elmininate min
                if(arr[end] < ans){
                    index = mid;
                    ans = arr[mid];
                }
                end = mid-1;
            }
        }
        return index;
	}

};