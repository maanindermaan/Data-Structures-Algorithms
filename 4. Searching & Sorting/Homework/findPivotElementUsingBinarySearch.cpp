// // Find the pivot element using Binary Search
// #include<iostream>
// using namespace std;

// int pivotBinary(int arr[] , int size){
//     int start = 0;
//     int end = size-1;
//     while(start<=end){
//         if(start==end){
//             return start;
//         }
//         int mid = start + (end-start)/2;
//         if(arr[mid]>arr[mid+1]){
//             return mid;
//         }
//         else if(arr[mid]<arr[mid-1]){
//             return mid-1;
//         }
//         else if(arr[start]>=arr[mid]){
//             // Move Left
//             end = mid-1;
//         }
//         else{
//             // Move Right
//             start = mid+1;
//         }
//     }
//     return -1;
// }

// int main(){
//     int arr[] = {5,6,7,8,1,2,3,4};
//     int size = sizeof(arr)/sizeof(arr[0]);

//     int ans = pivotBinary(arr,size);

//     if(ans == -1){
//         cout<<"No pivot element found.";
//     }
//     else{
//         cout<<"The pivot element is at "<<ans<<" index i.e. "<<arr[ans];
//     }
// return 0;
// }


// Find the pivot element using Binary Search
#include<iostream>
using namespace std;

int pivotBinary(int arr[] , int size){
    int start = 0;
    int end = size-1;
    while(start<=end){
        // 1. Checking if one element
        if(start == end){
            return start;
        }

        // 2. checking return statement
        int mid = start + (end-start)/2;
        if(arr[mid] > arr[mid+1]){
            return mid;
        }
        else if(arr[mid] < arr[mid-1]){
            return mid-1;
        }

        // 3. Using binary Search Logic
        else if(arr[start] >= arr[mid]){
            // left mein aajao right mein kya karoge
            end = mid-1;
        }
        else{
            // right mein jao
            start = mid+1;
        }
    }
    return -1;
}

int main(){
    int arr[] = {5,6,7,8,1,2,3,4};
    int size = sizeof(arr)/sizeof(arr[0]);

    int ans = pivotBinary(arr,size);

    if(ans == -1){
        cout<<"No pivot element found.";
    }
    else{
        cout<<"The pivot element is at "<<ans<<" index i.e. "<<arr[ans];
    }
return 0;
}