#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int binarySearch(int arr[] , int size , int target){
    int s = 0;
    int e = size-1;
    int mid = s+(e-s)/2;

    while(s<=e){
        if(arr[mid] == target){
            return mid;
        }
        else if(arr[mid] > target){
            e = mid-1;
        }
        else{
            s = mid+1;
        }
        mid = s + (e-s)/2;
    }
    return -1;
}

int main(){
    int arr[] = {2,4,6,8,10,12,14,16};
    int size = 8;
    int target= 14;
    int ans = binarySearch(arr , size , target);
    if(ans==-1){
        cout<<"Element not found"<<endl;
    }
    else{
        cout<<"Element found at index : "<<ans;
    }

return 0;
}