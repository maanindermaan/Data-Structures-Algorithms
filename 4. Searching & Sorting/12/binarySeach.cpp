#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// int binarySearch(int arr[] , int size , int target){
//     int start = 0;
//     int end = size-1;
//     int mid = (start + end)/2;

//     while(start<=end){

//         if(target == arr[mid]){
//             // Element found
//             return mid;
//         }
//         else if(target<arr[mid]){
//             // Search in left
//             end = mid-1;
//         }
//         else{
//             //Search in right
//             start = mid+1;
//         }

//         //calculate mid again because mid will be updated due to above two elseif and else loops
//         mid = (start+end)/2;
//     }

//     // Element not found
//     return -1;
// }

int main(){
    // int arr[] = {2,4,6,8,10,12,14,16};
    // int size = 8;
    // int target= 14;
    // int ans = binarySearch(arr , size , target);
    // if(ans==-1){
    //     cout<<"Element not found"<<endl;
    // }
    // else{
    //     cout<<"Element found at index : "<<ans;
    // }

    vector<int>arr{1,2,3,4,5,6,7};
    int arr1[] = {1,2,3,4,5,6,7,8};
    int size = 8;

    if(binary_search(arr.begin() , arr.end() , 3)){//3 ko find karo->for vector
        cout<<"Found";
    }
    else{
        cout<<"Not found";
    }
    if(binary_search(arr1, arr1+size , 3)){
        cout<<"Found";
    }
    else{
        cout<<"Not found";
    }

return 0;
}