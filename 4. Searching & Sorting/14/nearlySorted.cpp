// Binary Search in nearly sorted array
#include<iostream>
using namespace std;

int binarySearchInNearlySorted(int arr[] , int size , int target){
    int start = 0;
    int end = size-1;
    while(start<=end){
        int mid = start+(end-start)/2;
        if(arr[mid] == target){
            return mid;
        }
        else if(mid-1 >=0 && arr[mid-1] == target){//mid-1 index should be 0 or more than 0 and mid-1>=start
            return mid-1;
        }
        else if(mid+1 <= (size-1) && arr[mid+1]==target){ //mid-1 index should be 0 or more than 0 we should write mid+1<=end
            return mid+1;
        }
        else if(target>arr[mid]){
            // Right Side
            start = mid+2;
        }
        else{
            // Left Side
            end = mid-2;
        }
    }
    return -1;
}

int main(){
    int arr[] = {10 , 3, 40 , 20 , 50 , 80 , 70};
    int size = sizeof(arr)/sizeof(arr[0]);
    int target = 70;
    int ans = binarySearchInNearlySorted(arr , size, target);

    cout<<"The element is present at "<<ans<<" index.";
return 0;
}
