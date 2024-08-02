#include<iostream>
using namespace std;

int oddOccuringElement(int arr[] , int size){
    int start = 0;
    int end = size-1;

    while(start<=end){
        int mid = start + (end - start)/2;

        // SINGLE ELEMENT
        if(start == end){
            return start;
        }

        // FOR MID-EVEN
        if(mid%2==0){
            if(arr[mid] == arr[mid+1]){
                start = mid+2;
            }
            else{
                end = mid;
            }
        }
        // FOR MID- ODD
        else{
            if(arr[mid]==arr[mid-1]){
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }
    }
    return -1;
}

int main(){
    // int arr[] = {1,1,2,2,3,3,4,4,3,600,600,4,4};
    // int arr[] = {1,1,2,2,3,3,4,4,5,5,6,6,7,7,1,1,2,2,3,100,100};
    int arr[] = {1,1,2,2,3,3,4,5,5,6,6,7,7,1,1,2,2,3,3,100,100};
    int size = sizeof(arr)/sizeof(arr[0]);

    int ans = oddOccuringElement(arr , size);
    cout<<"The odd occuring element is : "<<arr[ans]<<" at index "<<ans;
return 0;
}