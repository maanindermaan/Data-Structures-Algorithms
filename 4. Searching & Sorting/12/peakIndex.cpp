// Find the peakIndexInMountainArray of the vector 
#include<iostream>
#include<vector>
using namespace std;

int peakIndexInMountainArray(vector<int>arr){
    int s = 0;
    int e = arr.size()-1;
    int mid = s+(e-s)/2;

    while(s<e){ //<= karenge toh infinite loop mein fasjenge
        if(arr[mid]<arr[mid+1]){
            // We are at line A and move to right
            s = mid+1;
        }
        else{
            // we are at line B move to Line A with peak index in consideration
            // because isme hume search ni karna peak index dena hai bas or agar mid-1 karunga toh elements loss hojaynege
            e = mid;
        }
        mid = s+(e-s)/2;
    }
    return s;
}

int main(){
    vector<int>arr{0,10,5,2};

    int ans = peakIndexInMountainArray(arr);

    cout<<"The peak Element is at index : "<<ans;


return 0;
}