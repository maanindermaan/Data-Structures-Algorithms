// // search In Rotated And Sorted 2nd Method
// #include<iostream>
// using namespace std;

// int findPivot(int arr[] , int size){
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

// int binarySearch(int arr[] , int s , int e , int size , int key){
//     // s=0;
//     // e=size-1;
//     while(s<=e){
//         int mid = s+(e-s)/2;
//         if(arr[mid] == key){
//             return mid;
//         }
//         else if(key>arr[mid]){
//             // Right Part
//             s = mid+1;
//         }
//         else{
//             // Left Part
//             e = mid-1;
//         }
//     }
//     return -1;
// }

// int searchInRotatedAndSorted2ndMethod(int arr[] , int size , int key){

//     int pivot = findPivot(arr , size);
//     int ans = 0;

//     if(key>=arr[0] && key<=pivot){
//         ans = binarySearch(arr , 0 , pivot , size , key);
//     }
//     else{
//         ans = binarySearch(arr , pivot+1 , (size-1) , size , key);
//     }
//     return ans;
// }

// int main(){
//     int arr[] = {5,6,7,8,1,2,3,4};
//     int size = sizeof(arr)/sizeof(arr[0]);

//     int key = 4;

//     int ans = searchInRotatedAndSorted2ndMethod(arr , size , key);

//     if(ans == -1){
//         cout<<"No such key found.";
//     }
//     else{
//         cout<<"The given key is at "<<ans<<" index i.e. "<<arr[ans];
//     }
// return 0;
// }



// search In Rotated And Sorted 2nd Method
#include<iostream>
using namespace std;

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

int binarySearch(int arr[] , int s , int e , int size , int key){
    // s=0;
    // e=size-1;
    while(s<=e){
        int mid = s+(e-s)/2;
        if(arr[mid] == key){
            return mid;
        }
        else if(key>arr[mid]){
            // Right Part
            s = mid+1;
        }
        else{
            // Left Part
            e = mid-1;
        }
    }
    return -1;
}

int searchInRotatedAndSorted2ndMethod(int arr[] , int size , int key){
    int pivotIndex = findPivot(arr , size);
    int ans = 0;

    if(key >= arr[0] && key<=arr[pivotIndex]){
        ans = binarySearch(arr , 0 , pivotIndex , size , key);
    }
    else{
        ans = binarySearch(arr , pivotIndex+1 , size-1 , size , key);
    }
    return ans;
}

int main(){
    int arr[] = {5,6,7,8,1,2,3,4};
    int size = sizeof(arr)/sizeof(arr[0]);

    int key = 7;

    int ans = searchInRotatedAndSorted2ndMethod(arr , size , key);

    if(ans == -1){
        cout<<"No such key found.";
    }
    else{
        cout<<"The given key is at index "<<ans<<" i.e. "<<arr[ans];
    }
return 0;
}
