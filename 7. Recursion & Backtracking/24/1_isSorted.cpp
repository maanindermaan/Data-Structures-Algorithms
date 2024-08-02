#include<iostream>
#include<vector>
using namespace std;

bool checkSorted(vector<int>& arr , int n , int i){
    // Base Case
    if(i==n-1){
        return true;
    }

    // Ek case solve krdo
    if(arr[i+1]<arr[i]){
        return false;
    }

    // Baaki recursion sambhal lega
    checkSorted(arr,n,i+1);
}

// bool chk(vector<int>&arr , int n , int k){
//     if(k == n-1){
//         return true;
//     }
//     if(arr[k] > arr[k+1]){
//         return false;
//     }
//     return chk(arr , n , k+1);
// }

int main(){
    vector<int> arr {10,20,30,40,50,60};
    int n = arr.size();
    int i = 0;

    bool isSorted = checkSorted(arr,n,i);
    if(isSorted){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
return 0;
}