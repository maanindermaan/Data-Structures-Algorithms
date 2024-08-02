// Find the total occurance of the vector 
#include<iostream>
#include<vector>
using namespace std;

int totalOccurance(vector<int>arr , int target){
    int s = 0;
    int e = arr.size()-1;
    int mid = (s+e)/2;
    int firstOcc = -1;

    while(s<=e){
        if(arr[mid]==target){
            // ans store and move left
            firstOcc = mid;
            e = mid-1;
        }
        else if(target>arr[mid]){
            // right
            s = mid+1;
        }
        else{
            // left
            e = mid-1;
        }
        mid = (s+e)/2;
    }
    s = 0;
    e = arr.size()-1;
    mid = (s+e)/2;
    int lastOcc=-1;
    while(s<=e){
        if(arr[mid]==target){
            // ans store and move right
            lastOcc = mid;
            s=mid+1;
        }
        else if(target>arr[mid]){
            // right
            s = mid+1;
        }
        else{
            // left
            e = mid-1;
        }
        mid = (s+e)/2;
    }
    return (lastOcc-firstOcc)+1;
}

int main(){
    vector<int>arr{1,3,4,4,4,4,4,4};
    int target = 4;

    int ans = totalOccurance(arr,target);

    cout<<"The element "<<target<<" is present "<<ans<<" times.";

return 0;
}