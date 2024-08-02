#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int>& arr , int key , int n , int s , int e){
    // Base Case
    // Case 1 -> key not found
    if(s > e){
        return -1;
    }
    // Case 2 -> Key found
    int mid = s+(e-s)/2;
    if(arr[mid] == key){
        return mid;
    } 

    // Ek case sambhal lo baaki recursion dekhlega
    if(key < arr[mid]){
        // move to left
        return binarySearch(arr , key , n , s , mid-1); // e = mid-1;
    }
    else{
        // move to 
        return binarySearch(arr , key , n , mid+1 , e);
    }

}

int bs(vector<int>&arr , int key , int n , int s , int e){
    // base case
    if(s>e){
        return -1;
    }

    int mid = s+(e-s)/2;

    if(arr[mid] == key){
        return mid;
    }
    if(key < arr[mid]){
        // left mein jao
        return bs(arr , key , n , s , mid-1);
    }
    else{
        return bs(arr , key , n , mid+1 , e);
    }

}

int main(){
    vector<int> arr{10,20,30,40,50,60};
    int key = 50;
    int n = arr.size()-1;

    int s = 0;
    int e = arr.size()-1;

    int ans = binarySearch(arr , key , n , s , e);
    cout<<ans;

return 0;
}