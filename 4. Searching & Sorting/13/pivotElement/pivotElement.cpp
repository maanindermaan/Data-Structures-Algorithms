// Find the pivot Element
#include<iostream>
#include<vector>
using namespace std;

int findPivot(vector<int>&arr){
    int s=0;
    int e=arr.size()-1;
    int mid=s+(e-s)/2;
    
    while(s<=e){
        if(mid+1 < arr.size() && arr[mid] > arr[mid+1]){
            return mid;
        }
        if(mid-1 >= 0 && arr[mid-1] > arr[mid]){
            return mid-1;
        }
        
        // left part -> becuase pivot is the max element as well
        if(arr[s] >= arr[mid]){
            e = mid-1;
        }
        
        // right part
        else{
            s = mid+1;
        }
        
        // update mid 
        mid = s+(e-s)/2;
    }
    return -1;
}

int main(){
    vector<int>arr{3,4,5,6,7,1,2};
    cout<<arr[findPivot(arr)];
    return 0;
}